package com.example.theamazonsgame;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.example.theamazonsgame.entities.Board;
import com.example.theamazonsgame.entities.Game;
import com.example.theamazonsgame.shared.ResultEnum;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.security.SecureRandom;
import java.text.SimpleDateFormat;
import java.util.Date;

public class MenuActivity extends AppCompatActivity {

    FirebaseUser firebaseUser;
    FirebaseAuth mAuth;
    FirebaseDatabase database;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        mAuth = FirebaseAuth.getInstance();
        firebaseUser = mAuth.getCurrentUser();
        database = FirebaseDatabase.getInstance("https://the-674ae-default-rtdb.europe-west1.firebasedatabase.app/");
    }


    public void createGame(View view) {
        String uuid = firebaseUser.getUid();
        String date = getCurrentDate();
        String gameId = uuid + " - " + date;

        DatabaseReference myRef = database.getReference("Games").child(gameId);
        Game game = getGameInstance(uuid, date, gameId);
        myRef.setValue(game);

        Intent intent = new Intent(MenuActivity.this, GameActivity.class);
        intent.putExtra("code", game.getCode());
        intent.putExtra("gameId", gameId);
        startActivity(intent);
    }

    private String getRandomKey(){
        SecureRandom random = new SecureRandom();
        int num = random.nextInt(1000000);
        return String.format("%06d", num);
    }

    private String getCurrentDate(){
        Date date = new Date();
        SimpleDateFormat formatter = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
        return formatter.format(date);
    }

    private Game getGameInstance(String uuid, String date, String gameId){
        return Game.builder()
                .player1(uuid)
                .code(getRandomKey())
                .date(date)
                .id(gameId)
                .time1("100000")
                .time2("100000")
                .result(ResultEnum.waitingForPlayer)
                .board(Board.createNewBoard())
                .build();
    }

    public void findGame(View view) {
        Intent intent = new Intent(MenuActivity.this, FindGameActivity.class);
        startActivity(intent);
    }
}
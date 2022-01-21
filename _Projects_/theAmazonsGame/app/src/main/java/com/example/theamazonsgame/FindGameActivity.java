package com.example.theamazonsgame;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import com.example.theamazonsgame.entities.Game;
import com.example.theamazonsgame.shared.ResultEnum;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.util.ArrayList;
import java.util.List;

public class FindGameActivity extends AppCompatActivity {

    FirebaseDatabase database;
    EditText codeEditText;
    FirebaseAuth mAuth;
    FirebaseUser firebaseUser;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_find_game);
        codeEditText = findViewById(R.id.findGame_enterCodeEditText);
        mAuth = FirebaseAuth.getInstance();
        firebaseUser = mAuth.getCurrentUser();

        database = FirebaseDatabase.getInstance("https://the-674ae-default-rtdb.europe-west1.firebasedatabase.app/");

    }

    public void findGame(View view) {
        List<Game> gamesList = new ArrayList<>();
        DatabaseReference myRef = database.getReference("Games");

        myRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot snapshot) {
                gamesList.clear();
                for (DataSnapshot postSnapshot: snapshot.getChildren()) {
                    Game game = postSnapshot.getValue(Game.class);
                    gamesList.add(game);
                }
               String code = codeEditText.getText().toString();
                for(Game game : gamesList){
                    if(game.getCode().equalsIgnoreCase(code)){

                        game.setResult(ResultEnum.firstMove);
                        game.setPlayer2(firebaseUser.getUid());
                        myRef.child(game.getId()).setValue(game);

                        Intent intent = new Intent(FindGameActivity.this, GameActivity.class);
                        intent.putExtra("gameId", game.getId());
                        myRef.removeEventListener(this);
                        startActivity(intent);
                    }
                }
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {
            }
        });
    }
}
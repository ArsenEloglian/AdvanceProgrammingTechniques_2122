package com.example.theamazonsgame;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.app.ProgressDialog;
import android.os.Bundle;
import android.util.Log;

import com.example.theamazonsgame.entities.Game;
import com.example.theamazonsgame.shared.ResultEnum;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class GameActivity extends AppCompatActivity {

    private ProgressDialog progressDialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game);
        Bundle extras = getIntent().getExtras();

        showProgressDialog(extras.getString("code"));

        FirebaseDatabase database = FirebaseDatabase.getInstance("https://the-674ae-default-rtdb.europe-west1.firebasedatabase.app/");
        DatabaseReference myRef = database.getReference("Games").child(extras.getString("gameId"));


        ValueEventListener postListener = new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                Game game = dataSnapshot.getValue(Game.class);
                if(game.getResult().value.equalsIgnoreCase(ResultEnum.firstMove.value)){
                    progressDialog.dismiss();
                }
            }
            @Override
            public void onCancelled(DatabaseError error) {
                // Failed to read value
            }
        };
        myRef.addValueEventListener(postListener);
    }

    private void showProgressDialog(String code){
        progressDialog = new ProgressDialog(GameActivity.this);
        progressDialog.setMessage("Waiting for second player... Your code : " + code);
        progressDialog.show();
    }
}
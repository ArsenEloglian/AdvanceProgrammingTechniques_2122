package com.example.theamazonsgame;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;

import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class FindGameActivity extends AppCompatActivity {

    FirebaseDatabase database;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_find_game);

        database = FirebaseDatabase.getInstance("https://the-674ae-default-rtdb.europe-west1.firebasedatabase.app/");
        DatabaseReference myRef = database.getReference("games");
    }

    public void findGame(View view) {

    }
}
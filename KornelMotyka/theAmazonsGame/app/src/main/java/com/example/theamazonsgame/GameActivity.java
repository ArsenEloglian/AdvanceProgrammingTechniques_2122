package com.example.theamazonsgame;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import android.app.ProgressDialog;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.util.Pair;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

import com.example.theamazonsgame.entities.Game;
import com.example.theamazonsgame.shared.BoardFieldEnum;
import com.example.theamazonsgame.shared.FieldStateEnum;
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

public class GameActivity extends AppCompatActivity {

    private ProgressDialog progressDialog;
    private TextView turnTextView;
    FirebaseAuth mAuth;
    FirebaseUser firebaseUser;
    private boolean isFirstPlayer = false;
    private boolean isYourTurn = false;
    ImageButton buttonA1,buttonA2,buttonA3,buttonA4,buttonA5,buttonB1,buttonB2,buttonB3,buttonB4,buttonB5,
    buttonC1,buttonC2,buttonC3,buttonC4,buttonC5,buttonD1,buttonD2,buttonD3,buttonD4,buttonD5,
    buttonE1,buttonE2,buttonE3,buttonE4,buttonE5;
    List<Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>>> fields;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game);
        Bundle extras = getIntent().getExtras();
        mAuth = FirebaseAuth.getInstance();
        firebaseUser = mAuth.getCurrentUser();
        turnTextView = findViewById(R.id.gameActivity_turnTextView);
        getButtonsFromLayout();

        showProgressDialog(extras.getString("code"));

        FirebaseDatabase database = FirebaseDatabase.getInstance("https://the-674ae-default-rtdb.europe-west1.firebasedatabase.app/");
        DatabaseReference myRef = database.getReference("Games").child(extras.getString("gameId"));

        ValueEventListener postListener = new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                Game game = dataSnapshot.getValue(Game.class);
                getIsFirstPlayer(game);
                if (game.getResult().value.equalsIgnoreCase(ResultEnum.firstMove.value)) {
                    progressDialog.dismiss();
                }
                setIsYourTurn(game);
                fields = getFields(game);
                setImagesToButtons();
            }

            @Override
            public void onCancelled(DatabaseError error) {
                // Failed to read value
            }
        };
        myRef.addValueEventListener(postListener);
    }

    private void setImagesToButtons() {
        for(Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> field : fields){
            ImageButton button = field.second.first;
            if(field.second.second.equals(FieldStateEnum.firstPlayerPawn)){
                button.setBackground(ContextCompat.getDrawable(getApplicationContext(),R.drawable.pawn_white));
                if(isYourTurn){
                    button.setEnabled(isFirstPlayer);
                }else{
                    button.setEnabled(false);
                }
            }else if(field.second.second.equals(FieldStateEnum.secondPlayerPawn)){
                button.setBackground(ContextCompat.getDrawable(getApplicationContext(),R.drawable.pawn));
                if(isYourTurn){
                    button.setEnabled(!isFirstPlayer);
                }else{
                    button.setEnabled(false);
                }
            }else if(field.second.second.equals(FieldStateEnum.fired)){
                button.setBackground(ContextCompat.getDrawable(getApplicationContext(),R.drawable.fired));
                button.setEnabled(false);
            } else if(field.second.second.equals(FieldStateEnum.empty)){
                button.setBackgroundColor(Color.TRANSPARENT);
                button.setEnabled(false);
            }
        }
    }

    private List<Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>>> getFields(Game game) {
        List<Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>>> fields = new ArrayList();
        fields.add(Pair.create(BoardFieldEnum.A1,Pair.create(buttonA1,game.getBoard().getA1())));
        fields.add(Pair.create(BoardFieldEnum.A2,Pair.create(buttonA2,game.getBoard().getA2())));
        fields.add(Pair.create(BoardFieldEnum.A3,Pair.create(buttonA3,game.getBoard().getA3())));
        fields.add(Pair.create(BoardFieldEnum.A4,Pair.create(buttonA4,game.getBoard().getA4())));
        fields.add(Pair.create(BoardFieldEnum.A5,Pair.create(buttonA5,game.getBoard().getA5())));
        fields.add(Pair.create(BoardFieldEnum.B1,Pair.create(buttonB1,game.getBoard().getB1())));
        fields.add(Pair.create(BoardFieldEnum.B2,Pair.create(buttonB2,game.getBoard().getB2())));
        fields.add(Pair.create(BoardFieldEnum.B3,Pair.create(buttonB3,game.getBoard().getB3())));
        fields.add(Pair.create(BoardFieldEnum.B4,Pair.create(buttonB4,game.getBoard().getB4())));
        fields.add(Pair.create(BoardFieldEnum.B5,Pair.create(buttonB5,game.getBoard().getB5())));
        fields.add(Pair.create(BoardFieldEnum.C1,Pair.create(buttonC1,game.getBoard().getC1())));
        fields.add(Pair.create(BoardFieldEnum.C2,Pair.create(buttonC2,game.getBoard().getC2())));
        fields.add(Pair.create(BoardFieldEnum.C3,Pair.create(buttonC3,game.getBoard().getC3())));
        fields.add(Pair.create(BoardFieldEnum.C4,Pair.create(buttonC4,game.getBoard().getC4())));
        fields.add(Pair.create(BoardFieldEnum.C5,Pair.create(buttonC5,game.getBoard().getC5())));
        fields.add(Pair.create(BoardFieldEnum.D1,Pair.create(buttonD1,game.getBoard().getD1())));
        fields.add(Pair.create(BoardFieldEnum.D2,Pair.create(buttonD2,game.getBoard().getD2())));
        fields.add(Pair.create(BoardFieldEnum.D3,Pair.create(buttonD3,game.getBoard().getD3())));
        fields.add(Pair.create(BoardFieldEnum.D4,Pair.create(buttonD4,game.getBoard().getD4())));
        fields.add(Pair.create(BoardFieldEnum.D5,Pair.create(buttonD5,game.getBoard().getD5())));
        fields.add(Pair.create(BoardFieldEnum.E1,Pair.create(buttonE1,game.getBoard().getE1())));
        fields.add(Pair.create(BoardFieldEnum.E2,Pair.create(buttonE2,game.getBoard().getE2())));
        fields.add(Pair.create(BoardFieldEnum.E3,Pair.create(buttonE3,game.getBoard().getE3())));
        fields.add(Pair.create(BoardFieldEnum.E4,Pair.create(buttonE4,game.getBoard().getE4())));
        fields.add(Pair.create(BoardFieldEnum.E5,Pair.create(buttonE5,game.getBoard().getE5())));

        return fields;
    }

    private void getButtonsFromLayout(){
        buttonA1 = findViewById(R.id.buttonA1);
        buttonA2 = findViewById(R.id.buttonA2);
        buttonA3 = findViewById(R.id.buttonA3);
        buttonA4 = findViewById(R.id.buttonA4);
        buttonA5 = findViewById(R.id.buttonA5);
        buttonB1 = findViewById(R.id.buttonB1);
        buttonB2 = findViewById(R.id.buttonB2);
        buttonB3 = findViewById(R.id.buttonB3);
        buttonB4 = findViewById(R.id.buttonB4);
        buttonB5 = findViewById(R.id.buttonB5);
        buttonC1 = findViewById(R.id.buttonC1);
        buttonC2 = findViewById(R.id.buttonC2);
        buttonC3 = findViewById(R.id.buttonC3);
        buttonC4 = findViewById(R.id.buttonC4);
        buttonC5 = findViewById(R.id.buttonC5);
        buttonD1 = findViewById(R.id.buttonD1);
        buttonD2 = findViewById(R.id.buttonD2);
        buttonD3 = findViewById(R.id.buttonD3);
        buttonD4 = findViewById(R.id.buttonD4);
        buttonD5 = findViewById(R.id.buttonD5);
        buttonE1 = findViewById(R.id.buttonE1);
        buttonE2 = findViewById(R.id.buttonE2);
        buttonE3 = findViewById(R.id.buttonE3);
        buttonE4 = findViewById(R.id.buttonE4);
        buttonE5 = findViewById(R.id.buttonE5);
    }

    private void setTurnTextView() {

        if (isYourTurn) {
            turnTextView.setText("YOUR TURN");
        } else {
            turnTextView.setText("OPPONENT TURN");
        }
    }

    private void setIsYourTurn(Game game) {
        if (isFirstPlayer && game.getResult().value.equalsIgnoreCase(ResultEnum.firstMove.value) ||
                !isFirstPlayer && game.getResult().value.equalsIgnoreCase(ResultEnum.secondMove.value)) {
            isYourTurn = true;
        } else {
            isYourTurn = false;
        }
        setTurnTextView();
    }

    private void getIsFirstPlayer(Game game) {
        isFirstPlayer = game.getPlayer1().equalsIgnoreCase(firebaseUser.getUid());
    }

    private void showProgressDialog(String code) {
        progressDialog = new ProgressDialog(GameActivity.this);
        progressDialog.setMessage("Waiting for second player... Your code : " + code);
        progressDialog.show();
    }

    public void click(View view) {
        Log.d("log", "enable :D");
    }
}
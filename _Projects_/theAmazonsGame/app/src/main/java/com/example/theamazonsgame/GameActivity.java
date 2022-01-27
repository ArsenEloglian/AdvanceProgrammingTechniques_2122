package com.example.theamazonsgame;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import android.app.ProgressDialog;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Pair;
import android.view.View;
import android.widget.ImageButton;
import android.widget.TextView;

import com.example.theamazonsgame.entities.Board;
import com.example.theamazonsgame.entities.Game;
import com.example.theamazonsgame.shared.BoardFieldEnum;
import com.example.theamazonsgame.shared.FieldStateEnum;
import com.example.theamazonsgame.shared.ResultEnum;
import com.example.theamazonsgame.shared.TurnStateEnum;
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
    FirebaseDatabase database;
    Game game;
    private boolean isFirstPlayer = false;
    private boolean isYourTurn = false;
    ImageButton buttonA1, buttonA2, buttonA3, buttonA4, buttonA5, buttonB1, buttonB2, buttonB3, buttonB4, buttonB5,
            buttonC1, buttonC2, buttonC3, buttonC4, buttonC5, buttonD1, buttonD2, buttonD3, buttonD4, buttonD5,
            buttonE1, buttonE2, buttonE3, buttonE4, buttonE5;
    List<Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>>> fields;
    TurnStateEnum turnState = TurnStateEnum.choosePawn;
    String pawnToMove;

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

        database = FirebaseDatabase.getInstance("https://the-674ae-default-rtdb.europe-west1.firebasedatabase.app/");
        DatabaseReference myRef = database.getReference("Games").child(extras.getString("gameId"));

        ValueEventListener postListener = new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                game = dataSnapshot.getValue(Game.class);
                getIsFirstPlayer(game);
                if (game.getResult().value.equalsIgnoreCase(ResultEnum.firstMove.value)) {
                    progressDialog.dismiss();
                }
                setIsYourTurn(game);
                fields = getFieldsFromDB(game);
                setImagesToButtons();
            }

            @Override
            public void onCancelled(DatabaseError error) {
                // Failed to read value
            }
        };
        myRef.addValueEventListener(postListener);
    }

    private Board fromButtonsToNewBoard(){
        List<ImageButton> listOfButtons = getListOfButtons();
        Board board = new Board();
        ImageButton buttonInCase;
        for(ImageButton button : listOfButtons){
            String id = getResources().getResourceEntryName(button.getId());
            switch (id){
                case "A1":
                     buttonInCase = buttonA1;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setA1(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setA1(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setA1(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setA1(FieldStateEnum.empty);
                    }
                    break;
                case "A2":
                    buttonInCase = buttonA2;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setA2(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setA2(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setA2(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setA2(FieldStateEnum.empty);
                    }
                    break;
                case "A3":
                    buttonInCase = buttonA3;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setA3(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setA3(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setA3(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setA3(FieldStateEnum.empty);
                    }
                    break;
                case "A4":
                    buttonInCase = buttonA4;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setA4(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setA4(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setA4(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setA4(FieldStateEnum.empty);
                    }
                    break;
                case "A5":
                    buttonInCase = buttonA5;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setA5(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setA5(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setA5(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setA5(FieldStateEnum.empty);
                    }
                    break;
                case "B1":
                    buttonInCase = buttonB1;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setB1(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setB1(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setB1(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setB1(FieldStateEnum.empty);
                    }
                    break;
                case "B2":
                    buttonInCase = buttonB2;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setB2(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setB2(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setB2(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setB2(FieldStateEnum.empty);
                    }
                    break;
                case "B3":
                    buttonInCase = buttonB3;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setB3(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setB3(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setB3(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setB3(FieldStateEnum.empty);
                    }
                    break;
                case "B4":
                    buttonInCase = buttonB4;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setB4(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setB4(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setB4(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setB4(FieldStateEnum.empty);
                    }
                    break;
                case "B5":
                    buttonInCase = buttonB5;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setB5(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setB5(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setB5(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setB5(FieldStateEnum.empty);
                    }
                    break;
                case "C1":
                    buttonInCase = buttonC1;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setC1(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setC1(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setC1(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setC1(FieldStateEnum.empty);
                    }
                    break;
                case "C2":
                    buttonInCase = buttonC2;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setC2(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setC2(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setC2(FieldStateEnum.secondPlayerPawn);
                    }else{
                    board.setC2(FieldStateEnum.empty);
                }
                    break;
                case "C3":
                    buttonInCase = buttonC3;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setC3(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setC3(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setC3(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setC3(FieldStateEnum.empty);
                    }
                    break;
                case "C4":
                    buttonInCase = buttonC4;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setC4(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setC4(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setC4(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setC4(FieldStateEnum.empty);
                    }
                    break;
                case "C5":
                    buttonInCase = buttonC5;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setC5(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setC5(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setC5(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setC5(FieldStateEnum.empty);
                    }
                    break;
                case "D1":
                    buttonInCase = buttonD1;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setD1(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setD1(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setD1(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setD1(FieldStateEnum.empty);
                    }
                    break;
                case "D2":
                    buttonInCase = buttonD2;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setD2(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setD2(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setD2(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setD2(FieldStateEnum.empty);
                    }
                    break;
                case "D3":
                    buttonInCase = buttonD3;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setD3(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setD3(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setD3(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setD3(FieldStateEnum.empty);
                    }
                    break;
                case "D4":
                    buttonInCase = buttonD4;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setD4(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setD4(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setD4(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setD4(FieldStateEnum.empty);
                    }
                    break;
                case "D5":
                    buttonInCase = buttonD5;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setD5(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setD5(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setD5(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setD5(FieldStateEnum.empty);
                    }
                    break;
                case "E1":
                    buttonInCase = buttonE1;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setE1(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setE1(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setE1(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setE1(FieldStateEnum.empty);
                    }
                    break;
                case "E2":
                    buttonInCase = buttonE2;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setE2(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setE2(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setE2(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setE2(FieldStateEnum.empty);
                    }
                    break;
                case "E3":
                    buttonInCase = buttonE3;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setE3(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setE3(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setE3(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setE3(FieldStateEnum.empty);
                    }
                    break;
                case "E4":
                    buttonInCase = buttonE4;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setE4(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setE4(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setE4(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setE4(FieldStateEnum.empty);
                    }
                    break;
                case "E5":
                    buttonInCase = buttonE5;
                    if(buttonInCase.getTag().equals(R.drawable.fired)){
                        board.setE5(FieldStateEnum.fired);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn_white)){
                        board.setE5(FieldStateEnum.firstPlayerPawn);
                    }else if(buttonInCase.getTag().equals(R.drawable.pawn)){
                        board.setE5(FieldStateEnum.secondPlayerPawn);
                    }else{
                        board.setE5(FieldStateEnum.empty);
                    }
                    break;
            }
        }
        return board;
    }

    private List<ImageButton> getListOfButtons(){
        List<ImageButton> list = new ArrayList<>();
        for(Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> field : fields){
            list.add(field.second.first);
        }
        return list;
    }

    private void setImagesToButtons() {
        for (Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> field : fields) {
            ImageButton button = field.second.first;
            if (field.second.second.equals(FieldStateEnum.firstPlayerPawn)) {
                button.setBackground(ContextCompat.getDrawable(getApplicationContext(), R.drawable.pawn_white));
                button.setTag(R.drawable.pawn_white);
                if (isYourTurn) {
                    button.setEnabled(isFirstPlayer);
                } else {
                    button.setEnabled(false);
                }
            } else if (field.second.second.equals(FieldStateEnum.secondPlayerPawn)) {
                button.setBackground(ContextCompat.getDrawable(getApplicationContext(), R.drawable.pawn));
                button.setTag(R.drawable.pawn);
                if (isYourTurn) {
                    button.setEnabled(!isFirstPlayer);
                } else {
                    button.setEnabled(false);
                }
            } else if (field.second.second.equals(FieldStateEnum.fired)) {
                button.setBackground(ContextCompat.getDrawable(getApplicationContext(), R.drawable.fired));
                button.setTag(R.drawable.fired);
                button.setEnabled(false);
            } else if (field.second.second.equals(FieldStateEnum.empty)) {
                button.setBackgroundColor(Color.TRANSPARENT);
                button.setTag("empty");
                button.setEnabled(false);
            }
        }
    }

    private List<Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>>> getFieldsFromDB(Game game) {
        List<Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>>> fields = new ArrayList();
        fields.add(Pair.create(BoardFieldEnum.A1, Pair.create(buttonA1, game.getBoard().getA1())));
        fields.add(Pair.create(BoardFieldEnum.A2, Pair.create(buttonA2, game.getBoard().getA2())));
        fields.add(Pair.create(BoardFieldEnum.A3, Pair.create(buttonA3, game.getBoard().getA3())));
        fields.add(Pair.create(BoardFieldEnum.A4, Pair.create(buttonA4, game.getBoard().getA4())));
        fields.add(Pair.create(BoardFieldEnum.A5, Pair.create(buttonA5, game.getBoard().getA5())));
        fields.add(Pair.create(BoardFieldEnum.B1, Pair.create(buttonB1, game.getBoard().getB1())));
        fields.add(Pair.create(BoardFieldEnum.B2, Pair.create(buttonB2, game.getBoard().getB2())));
        fields.add(Pair.create(BoardFieldEnum.B3, Pair.create(buttonB3, game.getBoard().getB3())));
        fields.add(Pair.create(BoardFieldEnum.B4, Pair.create(buttonB4, game.getBoard().getB4())));
        fields.add(Pair.create(BoardFieldEnum.B5, Pair.create(buttonB5, game.getBoard().getB5())));
        fields.add(Pair.create(BoardFieldEnum.C1, Pair.create(buttonC1, game.getBoard().getC1())));
        fields.add(Pair.create(BoardFieldEnum.C2, Pair.create(buttonC2, game.getBoard().getC2())));
        fields.add(Pair.create(BoardFieldEnum.C3, Pair.create(buttonC3, game.getBoard().getC3())));
        fields.add(Pair.create(BoardFieldEnum.C4, Pair.create(buttonC4, game.getBoard().getC4())));
        fields.add(Pair.create(BoardFieldEnum.C5, Pair.create(buttonC5, game.getBoard().getC5())));
        fields.add(Pair.create(BoardFieldEnum.D1, Pair.create(buttonD1, game.getBoard().getD1())));
        fields.add(Pair.create(BoardFieldEnum.D2, Pair.create(buttonD2, game.getBoard().getD2())));
        fields.add(Pair.create(BoardFieldEnum.D3, Pair.create(buttonD3, game.getBoard().getD3())));
        fields.add(Pair.create(BoardFieldEnum.D4, Pair.create(buttonD4, game.getBoard().getD4())));
        fields.add(Pair.create(BoardFieldEnum.D5, Pair.create(buttonD5, game.getBoard().getD5())));
        fields.add(Pair.create(BoardFieldEnum.E1, Pair.create(buttonE1, game.getBoard().getE1())));
        fields.add(Pair.create(BoardFieldEnum.E2, Pair.create(buttonE2, game.getBoard().getE2())));
        fields.add(Pair.create(BoardFieldEnum.E3, Pair.create(buttonE3, game.getBoard().getE3())));
        fields.add(Pair.create(BoardFieldEnum.E4, Pair.create(buttonE4, game.getBoard().getE4())));
        fields.add(Pair.create(BoardFieldEnum.E5, Pair.create(buttonE5, game.getBoard().getE5())));

        return fields;
    }

    private void getButtonsFromLayout() {
        buttonA1 = findViewById(R.id.A1);
        buttonA2 = findViewById(R.id.A2);
        buttonA3 = findViewById(R.id.A3);
        buttonA4 = findViewById(R.id.A4);
        buttonA5 = findViewById(R.id.A5);
        buttonB1 = findViewById(R.id.B1);
        buttonB2 = findViewById(R.id.B2);
        buttonB3 = findViewById(R.id.B3);
        buttonB4 = findViewById(R.id.B4);
        buttonB5 = findViewById(R.id.B5);
        buttonC1 = findViewById(R.id.C1);
        buttonC2 = findViewById(R.id.C2);
        buttonC3 = findViewById(R.id.C3);
        buttonC4 = findViewById(R.id.C4);
        buttonC5 = findViewById(R.id.C5);
        buttonD1 = findViewById(R.id.D1);
        buttonD2 = findViewById(R.id.D2);
        buttonD3 = findViewById(R.id.D3);
        buttonD4 = findViewById(R.id.D4);
        buttonD5 = findViewById(R.id.D5);
        buttonE1 = findViewById(R.id.E1);
        buttonE2 = findViewById(R.id.E2);
        buttonE3 = findViewById(R.id.E3);
        buttonE4 = findViewById(R.id.E4);
        buttonE5 = findViewById(R.id.E5);
    }

    private void setTurnTextView() {

        if (isYourTurn) {
            turnTextView.setText("YOUR TURN");
        } else {
            turnTextView.setText("OPPONENT TURN");
        }
    }

    private void setIsYourTurn(Game game) {
        isYourTurn = isFirstPlayer && game.getResult().value.equalsIgnoreCase(ResultEnum.firstMove.value) ||
                !isFirstPlayer && game.getResult().value.equalsIgnoreCase(ResultEnum.secondMove.value);
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
        String field = getResources().getResourceEntryName(view.getId());
        char firstCondition = field.charAt(0);
        char secondCondition = field.charAt(1);
        Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> fieldFromList = getFieldFromList(field);
        if (fieldFromList.second.first.getTag().equals(R.drawable.dot) && turnState == TurnStateEnum.choosePawn) {
            turnState = TurnStateEnum.chooseMove;
        } else if (fieldFromList.second.first.getTag().equals(R.drawable.dot) && turnState == TurnStateEnum.chooseMove) {
            turnState = TurnStateEnum.chooseFire;
        }

        if (turnState.equals(TurnStateEnum.choosePawn)) {
            pawnToMove = field;
            choosePawn(field, firstCondition, secondCondition);
        } else if (turnState.equals(TurnStateEnum.chooseMove)) {
            for (Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> f : fields) {
                if (field.equalsIgnoreCase(f.first.firstValue + f.first.secondValue)) {
                    if (isFirstPlayer) {
                        f.second.first.setBackground(ContextCompat.getDrawable(getApplicationContext(), R.drawable.pawn_white));
                        f.second.first.setTag(R.drawable.pawn_white);
                    } else {
                        f.second.first.setBackground(ContextCompat.getDrawable(getApplicationContext(), R.drawable.pawn));
                        f.second.first.setTag(R.drawable.pawn);
                    }
                    f.second.first.setEnabled(false);
                } else if (pawnToMove.equalsIgnoreCase(f.first.firstValue + f.first.secondValue) || f.second.first.getTag().equals(R.drawable.dot)) {
                    f.second.first.setBackgroundColor(Color.TRANSPARENT);
                    f.second.first.setTag("empty");
                    f.second.first.setEnabled(false);
                }
            }
            disableAllFields();
            //pokazywanie kropek dla strzalu
            int firstEdgeE = (int)'E';
            int firstEdgeA = (int)'A';
            int secondEdge1 = 1;
            int secondEdge5 = 5;
            List<String> fieldsToDot = new ArrayList<>();
            for (int i = 1; i <= 4; i++) {
                int firstC = fieldFromList.first.firstValue.charAt(0) + i;
                int secondC = Integer.parseInt(fieldFromList.first.secondValue) + i;
                String firstAndSecondC = String.valueOf((char)firstC) + secondC;
                if(firstC >= firstEdgeA && firstC <= firstEdgeE && secondC >= secondEdge1 && secondC <= secondEdge5){
                    if(getFieldFromList(firstAndSecondC).second.first.getTag().equals("empty")){
                        fieldsToDot.add(firstAndSecondC);
                    }
                }
                firstC = fieldFromList.first.firstValue.charAt(0) - i;
                secondC = Integer.parseInt(fieldFromList.first.secondValue) - i;
                firstAndSecondC = String.valueOf((char)firstC) + secondC;
                if(firstC >= firstEdgeA && firstC <= firstEdgeE && secondC >= secondEdge1 && secondC <= secondEdge5){
                    if(getFieldFromList(firstAndSecondC).second.first.getTag().equals("empty")){
                        fieldsToDot.add(firstAndSecondC);
                    }
                }
                firstC = fieldFromList.first.firstValue.charAt(0) - i;
                secondC = Integer.parseInt(fieldFromList.first.secondValue) + i;
                firstAndSecondC = String.valueOf((char)firstC) + secondC;
                if(firstC >= firstEdgeA && firstC <= firstEdgeE && secondC >= secondEdge1 && secondC <= secondEdge5){
                    if(getFieldFromList(firstAndSecondC).second.first.getTag().equals("empty")){
                        fieldsToDot.add(firstAndSecondC);
                    }
                }
                firstC = fieldFromList.first.firstValue.charAt(0) + i;
                secondC = Integer.parseInt(fieldFromList.first.secondValue) - i;
                firstAndSecondC = String.valueOf((char)firstC) + secondC;
                if(firstC >= firstEdgeA && firstC <= firstEdgeE && secondC >= secondEdge1 && secondC <= secondEdge5){
                    if(getFieldFromList(firstAndSecondC).second.first.getTag().equals("empty")){
                        fieldsToDot.add(firstAndSecondC);
                    }
                }
            }

            for (String fieldToChange : fieldsToDot) {
                for (Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> f : fields) {
                    if ((f.first.firstValue + f.first.secondValue).equalsIgnoreCase(fieldToChange)) {
                        f.second.first.setBackground(ContextCompat.getDrawable(getApplicationContext(), R.drawable.dot));
                        f.second.first.setTag(R.drawable.dot);
                        f.second.first.setEnabled(true);
                    }
                }
            }

            if(fieldsToDot.isEmpty()){
                setBoardToDatabase();
            }

        }else if (turnState.equals(TurnStateEnum.chooseFire)){
            for (Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> f : fields) {
                if ((f.first.firstValue + f.first.secondValue).equalsIgnoreCase(field)) {
                    f.second.first.setBackground(ContextCompat.getDrawable(getApplicationContext(), R.drawable.fired));
                    f.second.first.setTag(R.drawable.fired);
                    f.second.first.setEnabled(false);
                }
            }
            setBoardToDatabase();
        }
    }

    private void setBoardToDatabase(){
        DatabaseReference myRef = database.getReference("Games").child(game.getId());
        if(isFirstPlayer){
            game.setResult(ResultEnum.secondMove);
        }else{
            game.setResult(ResultEnum.firstMove);
        }
        game.setBoard(fromButtonsToNewBoard());
        myRef.setValue(game);
        turnState = TurnStateEnum.choosePawn;
    }

    private void disableAllFields() {
        for(Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> field : fields){
            field.second.first.setEnabled(false);
        }
    }

    private void choosePawn(String field, char firstCondition, char secondCondition) {
        List<String> fieldsToChange = new ArrayList<>();
        for (char alph = 'A'; alph <= 'E'; alph++) {
            String f = alph + String.valueOf(secondCondition);
            Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> fieldFromList = getFieldFromList(f);
            if (!(fieldFromList.first.firstValue + fieldFromList.first.secondValue).equalsIgnoreCase(field) &&
                    (fieldFromList.second.first.getTag().equals("empty") || fieldFromList.second.first.getTag().equals(R.drawable.dot))) {
                fieldsToChange.add(f);
            }
        }

        for (int i = 1; i <= 5; i++) {
            String f = firstCondition + String.valueOf(i);
            Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> fieldFromList = getFieldFromList(f);
            if (!(fieldFromList.first.firstValue + fieldFromList.first.secondValue).equalsIgnoreCase(field) &&
                    (fieldFromList.second.first.getTag().equals("empty") || fieldFromList.second.first.getTag().equals(R.drawable.dot))) {
                fieldsToChange.add(f);
            }
        }

        for (String fieldToChange : fieldsToChange) {
            for (Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> fieldFromList : fields) {
                if ((fieldFromList.first.firstValue + fieldFromList.first.secondValue).equalsIgnoreCase(fieldToChange)) {
                    fieldFromList.second.first.setBackground(ContextCompat.getDrawable(getApplicationContext(), R.drawable.dot));
                    fieldFromList.second.first.setTag(R.drawable.dot);
                    fieldFromList.second.first.setEnabled(true);
                } else if (fieldFromList.second.first.getTag().equals(R.drawable.dot) && !isFieldInList(fieldsToChange, (fieldFromList.first.firstValue + fieldFromList.first.secondValue))) {
                    fieldFromList.second.first.setBackgroundColor(Color.TRANSPARENT);
                    fieldFromList.second.first.setTag("empty");
                    fieldFromList.second.first.setEnabled(false);
                }
            }
        }
    }

    private boolean isFieldInList(List<String> list, String field) {
        for (String a : list) {
            if (a.equalsIgnoreCase(field)) {
                return true;
            }
        }
        return false;
    }

    private Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> getFieldFromList(String field) {
        for (Pair<BoardFieldEnum, Pair<ImageButton, FieldStateEnum>> f : fields) {
            String conditions = f.first.firstValue + f.first.secondValue;
            if (conditions.equalsIgnoreCase(field)) {
                return f;
            }
        }
        return null;
    }
}
package com.amazon.game;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class AmazonApp extends Application {

    public static final int TILE_SIZE = 50;
    public static final int WIDTH = 10;
    public static final int HEIGHT = 10;

    private Board board;
    private Label status;
    private Label move;
    private ImageView imgMove;
    private Image white_queen = new Image("/res/white_queen.png",50,50,false,false);
    private Image black_queen = new Image("/res/black_queen.png",50,50,false,false);
    private static AmazonApp instance;

    public static void displayStatusText(String text) {
        instance.status.setText(text);
    }

    private Parent createContent() {
        BorderPane root = new BorderPane();
        Pane table = new Pane();
        board = new Board();
        table.setPrefSize(10*50,10*50);
        table.getChildren().addAll(board.getTileGroup(),board.getArrowsGroup(),board.getCirclesGroup(),board.getQueensGroup());
        root.setCenter(table);
        GridPane menu = new GridPane();
        BorderPane vbox = new BorderPane();
        GridPane gridPane = new GridPane();

        move = new Label();
        move.setFont(new Font(20));
        move.setText("Ruch gracza:");
        move.setPadding(new Insets(10,10,10,10));

        imgMove = new ImageView();
        imgMove.setImage(white_queen);

        status = new Label();
        status.setFont(new Font(20));
        status.setPadding(new Insets(10,10,10,10));

        menu.setPadding(new Insets(20,20,20,20));
        Button reset = new Button();
        reset.setText("Reset");
        reset.setAlignment(Pos.CENTER);
        reset.setOnMouseClicked(event -> {board.clearBoard();imgMove.setImage(white_queen);status.setText("");});

        gridPane.add(move,1,1);
        gridPane.add(imgMove,2,1);
        vbox.setPadding(new Insets(20,20,20,20));
        vbox.setTop(gridPane);
        vbox.setCenter(status);
        vbox.setBottom(reset);
        vbox.setAlignment(reset,Pos.CENTER);
        root.setRight(vbox);
        return root;
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        instance = this;
        Scene scene = new Scene(createContent());
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.setTitle("Amazon Game");
        scene.setOnMouseClicked(event -> {
            if(board.getCurrentTurn() == Color.BLACK)
                imgMove.setImage(black_queen);
            if(board.getCurrentTurn() == Color.WHITE)
                imgMove.setImage(white_queen);
        });
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

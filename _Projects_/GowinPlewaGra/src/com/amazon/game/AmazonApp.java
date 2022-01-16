package com.amazon.game;

import javafx.application.Application;
import javafx.scene.*;
import javafx.scene.image.Image;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class AmazonApp extends Application {

    public static final int TILE_SIZE = 50;
    public static final int WIDTH = 10;
    public static final int HEIGHT = 10;

    private Board board;
    private Image white_queen = new Image("/res/white_queen.png",50,50,false,false);
    private Image black_queen = new Image("/res/black_queen.png",50,50,false,false);

    private Parent createContent() {
        BorderPane root = new BorderPane();
        Pane table = new Pane();
        board = new Board();
        table.setPrefSize(10*50,10*50);
        table.getChildren().addAll(board.getTileGroup(),board.getArrowsGroup(),board.getCirclesGroup(),board.getQueensGroup());
        root.setCenter(table);
        
        return root;
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        Scene scene = new Scene(createContent());
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.setTitle("Amazon Game");        
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

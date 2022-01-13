package com.amazon.game;

import javafx.scene.Group;
import javafx.scene.paint.Color;
import java.util.ArrayList;
import java.util.List;

public class Board{

    private Tile board [][] = new Tile[AmazonApp.WIDTH][AmazonApp.HEIGHT];
    private Group tileGroup = new Group();
    private Group queensGroup = new Group();    

    Board() {
        for(int y = 0; y < AmazonApp.HEIGHT; y++) {
            for(int x = 0; x < AmazonApp.WIDTH; x++) {
                Tile tile = new Tile(this,(x + y) % 2 == 0, x, y);
                board[x][y] = tile;
                tileGroup.getChildren().add(tile);
                Queen queen = null;
                if((y == 0 && (x == 3 || x == 6)) || (y == 3 && (x == 0 || x == 9))) {
                    queen = new Queen(Color.WHITE, x, y,tile);
                }
                if((y == 6 && (x == 0 || x == 9)) || (y == 9 && (x == 3 || x == 6))) {
                    queen = new Queen(Color.BLACK, x, y,tile);
                }
                if(queen != null) {
                    queensGroup.getChildren().add(queen);
                }
            }
        }
    }

    public Group getQueensGroup() {
        return queensGroup;
    }
    public Group getTileGroup() {
        return tileGroup;
    }    
}

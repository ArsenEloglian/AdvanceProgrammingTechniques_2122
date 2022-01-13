package com.amazon.game;

import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Tile extends Rectangle {    
    private int x;
    private int y;
    public Tile(Board board,boolean color, int x, int y) {
        this.x = x;
        this.y = y;
        setWidth(AmazonApp.TILE_SIZE);
        setHeight(AmazonApp.TILE_SIZE);
        relocate(x * AmazonApp.TILE_SIZE, y * AmazonApp.TILE_SIZE);
        setFill(color ? Color.valueOf("#ffce9e") : Color.valueOf("#d18847"));
        this.board = board;
    }
}

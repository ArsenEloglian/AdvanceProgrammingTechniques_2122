package com.amazon.game;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.paint.Color;

public class Queen extends ImageView {

    private Image white = new Image(getClass().getResourceAsStream("/res/white_queen.png"),50,50,false,false);
    private Image black = new Image(getClass().getResourceAsStream("/res/black_queen.png"),50,50,false,false);

    private Color color;
    private int x;
    private int y;
    private double mouseX;
    private double mouseY;
    private Tile tile;

    public Queen(Color color,int x, int y, Tile tile) {
        if(color == Color.BLACK)
            setImage(black);
        if(color == Color.WHITE)
            setImage(white);
        this.x = x;
        this.y = y;
        this.color = color;
        this.tile=tile;        
        relocate(x * AmazonApp.TILE_SIZE,y * AmazonApp.TILE_SIZE);
    }   
}

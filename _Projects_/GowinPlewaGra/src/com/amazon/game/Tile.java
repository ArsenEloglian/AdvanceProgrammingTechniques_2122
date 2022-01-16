package com.amazon.game;

import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import java.util.List;

public class Tile extends Rectangle {

    private Queen queen;
    private Board board;
    private Arrow arrow;
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
        setOnMousePressed(this::setOnMousePressed);

    }

    public boolean hasQueen() {
        return queen != null;
    }
    public Queen getQueen() {
        return queen;
    }
    public void setQueen(Queen queen) {
        this.queen = queen;
    }    
    public int getTileX(){return x;}
    public int getTileY(){return y;}
    public Board getBoard(){
        return board;
    }
    public void setLegalMoveOnTile() {
        LegalMove legalMove = new LegalMove(x,y);
        legalMove.setOnMousePressed(this::setOnMousePressed);
        board.addCirclesGroup(legalMove);
    }
    public void removeLegalMoveFromTile() {
        board.clearCirclesGroup();
    }
    private void setOnMousePressed(MouseEvent e) {
        
    }
}

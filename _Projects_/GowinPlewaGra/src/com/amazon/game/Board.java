package com.amazon.game;

import javafx.scene.Group;
import javafx.scene.paint.Color;
import java.util.ArrayList;
import java.util.List;

public class Board{

    private Tile board [][] = new Tile[AmazonApp.WIDTH][AmazonApp.HEIGHT];
    private List<Queen> whiteQueens = new ArrayList<Queen>();
    private List<Queen> blackQueens = new ArrayList<Queen>();
    private Group tileGroup = new Group();
    private Group queensGroup = new Group();
    private Group circlesGroup = new Group();
    private Group arrowsGroup = new Group();
    private Color currentTurn = Color.WHITE;
    private Tile ActiveTile;

    Board() {
        for(int y = 0; y < AmazonApp.HEIGHT; y++) {
            for(int x = 0; x < AmazonApp.WIDTH; x++) {
                Tile tile = new Tile(this,(x + y) % 2 == 0, x, y);
                board[x][y] = tile;
                tileGroup.getChildren().add(tile);
                Queen queen = null;
                if((y == 0 && (x == 3 || x == 6)) || (y == 3 && (x == 0 || x == 9))) {
                    queen = new Queen(Color.WHITE, x, y,tile);
                    whiteQueens.add(queen);
                }
                if((y == 6 && (x == 0 || x == 9)) || (y == 9 && (x == 3 || x == 6))) {
                    queen = new Queen(Color.BLACK, x, y,tile);
                    blackQueens.add(queen);
                }
                if(queen != null) {
                    queensGroup.getChildren().add(queen);
                    tile.setQueen(queen);
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
    public Group getCirclesGroup() {
        return circlesGroup;
    }
    public Group getArrowsGroup() {
        return arrowsGroup;
    }
    public void addArrowsGroup(Arrow arrow){
        arrowsGroup.getChildren().add(arrow);
    }
    public void addCirclesGroup(LegalMove legalMove) {
        circlesGroup.getChildren().add(legalMove);
    }
    public void clearCirclesGroup() {
        circlesGroup.getChildren().clear();
    }
    public Tile getTile(int x, int y) {
        return board[x][y];
    }
    public Color getCurrentTurn() {
        return currentTurn;
    }
    public void setCurrentTurn(Color currentTurn) {
        this.currentTurn = currentTurn;
    }
    public Tile getActiveTile() {
        return ActiveTile;
    }
    public void setActiveTile(Tile tile) {
        ActiveTile = tile;
    }
}

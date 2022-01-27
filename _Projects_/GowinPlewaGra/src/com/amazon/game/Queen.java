package com.amazon.game;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import java.util.ArrayList;
import java.util.List;

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
        setOnMouseEntered(e -> onMouseEntered());
        setOnMouseExited(e -> onMouseExited());
        setOnMouseDragged(this::onMouseDragged);
        setOnMousePressed(this::setOnMousePressed);
        setOnMouseReleased(this::setOnMouseReleased);
        relocate(x * AmazonApp.TILE_SIZE,y * AmazonApp.TILE_SIZE);
    }
    private void onMouseEntered() {
        if(this.canMove() && this.tile.getBoard().getActiveTile() == null && !isDragged) {
            for (Tile legalMove : getLegalMoves()) {
                legalMove.setLegalMoveOnTile();
            }
        }
    }
    private void onMouseExited() {
        if(this.canMove() && this.tile.getBoard().getActiveTile() == null&& !isDragged){
            for (Tile legalMove : getLegalMoves()) {
                legalMove.removeLegalMoveFromTile();
            }
        }
    }
    boolean isDragged = false;
    private void onMouseDragged(MouseEvent e) {
        if(this.canMove() && this.tile.getBoard().getActiveTile() == null) {
            if(e.getSceneX() > 500 || e.getSceneX() < 0 || e.getSceneY() > 500 || e.getSceneY() < 0) {
                relocate(x*50, y*50);
				isDragged=false;
            } else {
                relocate(e.getSceneX() - mouseX + (x * 50), e.getSceneY() - mouseY + (y * 50));
            }
        }
    }

    private void setOnMousePressed(MouseEvent e) {
        isDragged = true;
        if(this.canMove() && this.tile.getBoard().getActiveTile() == null) {
            mouseX = e.getSceneX();
            mouseY = e.getSceneY();
        }
    }
    private void setOnMouseReleased(MouseEvent e) {
        isDragged = false;
        if(this.canMove() && this.tile.getBoard().getActiveTile() == null) {
            double newX = e.getSceneX();
            double newY = e.getSceneY();

            if(newX > 500 || newX < 0 || newY > 500 || newY < 0)
                return;

            for (Tile legalMove : getLegalMoves()) {
                legalMove.removeLegalMoveFromTile();
            }

            if(getLegalMoves().contains(this.tile.getBoard().getTile((int)(newX/50),(int)(newY/50))) && canMove()) {
                move(this.tile.getBoard().getTile((int)(newX/50),(int)(newY/50)));
                for (Tile legalMove : getLegalMoves()) {
                    legalMove.setLegalMoveOnTile();
                }
                tile.getBoard().setActiveTile(tile);
            }
            else
                relocate(x*50, y*50);
        }
    }
    public void move(Tile tile) {
        tile.setQueen(this);
        if(this.tile != null)
            this.tile.setQueen(null);
        this.x = tile.getTileX();
        this.y = tile.getTileY();
        this.tile=tile;

        relocate(x*50, y*50);
    }
    public boolean canMove() {
        return this.tile.getBoard().getCurrentTurn() == this.color;
    }
    public int numberOfPossibleMoves() {
        return getLegalMoves().size();
    }
    public List<Tile> getLegalMoves() {
        List<Tile> legalMoves = new ArrayList<>();
        for(int i = 1; x + i <= 9; i++)
            if(!addLegalMove(x + i, y, legalMoves))
                break;
        for(int i = 1; x - i >= 0; i++)
            if(!addLegalMove(x - i, y, legalMoves))
                break;
        for(int i = 1; y + i <= 9; i++)
            if(!addLegalMove(x, y + i, legalMoves))
                break;
        for(int i = 1; y - i >= 0; i++)
            if(!addLegalMove(x, y - i, legalMoves))
                break;
        for(int i = 1; x + i <= 9 && y + i <= 9;i++)
            if(!addLegalMove(x + i, y + i, legalMoves))
                break;
        for(int i = 1; x + i <= 9 && y - i >= 0;i++)
            if(!addLegalMove(x + i, y - i, legalMoves))
                break;
        for(int i = 1; x - i >= 0 && y + i <= 9;i++)
            if(!addLegalMove(x - i, y + i, legalMoves))
                break;
        for(int i = 1; x - i >= 0 && y - i >= 0;i++)
            if(!addLegalMove(x - i, y - i, legalMoves))
                break;
        return legalMoves;
    }
    private boolean addLegalMove(int x, int y, List<Tile> legalMoves) {
        Tile tile = this.tile.getBoard().getTile(x, y);
        if(!tile.hasQueen() && !tile.hasArrow())
            legalMoves.add(tile);
        else
            return false;
        return true;
    }
}

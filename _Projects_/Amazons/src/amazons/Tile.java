package amazons;

import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Tile extends StackPane {
    private Piece piece;
    int oldX, oldY;
    private Tile[][] b;
    public static final int TILE_SIZE = 50;

    public void setPiece(Piece p) {
        this.piece = p;
        this.getChildren().addAll(this.piece);
    }

    public void movePiece(Tile[][] b, int targetX, int targetY) {
        Piece p = this.piece;
        this.piece = null;
        b[targetX][targetY].setPiece(p);
    }

    public Piece getPiece() {
        return this.piece;
    }

    public boolean hasPiece() {
        if(this.piece == null || this.piece.type == 2) {
            return false;
        }
        return true;
    }

    public void shootAt(Tile[][] b, int targetX, int targetY) {
        b[targetX][targetY].setPiece(new Piece(2));
    }

    public Tile(Tile[][] b, boolean light, int x, int y) {
        this.b = b;
        Rectangle t = new Rectangle(TILE_SIZE, TILE_SIZE);
        t.setFill(light ? Color.valueOf("#ffce9e") : Color.valueOf("#D18B47"));
        this.getChildren().addAll(t);
        this.setLayoutX(x * TILE_SIZE);
        this.setLayoutY(y * TILE_SIZE);

        setOnMousePressed(e -> {
            if(this.hasPiece()) {
                this.oldX = (int) (e.getSceneX() / 50);
                this.oldY = (int) (e.getSceneY() / 50);
            }
        });
        setOnMouseReleased(e -> {
            if(e.getSceneX() < 0 || e.getSceneY() < 0) return; //top bar / left side bugfix
            int newX = (int) (e.getSceneX() / 50);
            int newY = (int) (e.getSceneY() / 50);
            if(newX == oldX && newY == oldY) return; //not moved
            if(newX < 0 || newY < 0 || newX >= b.length || newY >= b.length) return; //mouse released out of window
            //checkIfLegalMove placeholder
            if(b[newX][newY].piece == null) {//checkIfEmpty
                if((newX == oldX && newY != oldY) || (newX != oldX && newY == oldY)) {//checkIfStraightLine
                    b[oldX][oldY].movePiece(b, newX, newY);
                }
                else if(Math.abs(newX-oldX) == Math.abs(newY-oldY)) {//checkIfDiagonal
                    b[oldX][oldY].movePiece(b, newX, newY);
                }
            }
        });
    }

}

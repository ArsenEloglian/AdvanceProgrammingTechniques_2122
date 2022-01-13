package amazons;

import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Tile extends StackPane {
    private Piece piece;
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
        if(this.piece == null) {
            return false;
        }
        return true;
    }

    public Tile(boolean light, int x, int y) {
        Rectangle t = new Rectangle(TILE_SIZE, TILE_SIZE);
        t.setFill(light ? Color.valueOf("#ffce9e") : Color.valueOf("#D18B47"));
        this.getChildren().addAll(t);
        this.setLayoutX(x * TILE_SIZE);
        this.setLayoutY(y * TILE_SIZE);
    }

}

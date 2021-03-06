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

    public void removePiece(Tile[][] b, int targetX, int targetY) {
        if (this.piece == null) return;
        b[targetX][targetY].piece.image.setImage(null);
        b[targetX][targetY].piece = null;
    }

    public void movePiece(Tile[][] b, int targetX, int targetY) {
        if (this.piece == null) return; //bugfix on wall drag
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

    public boolean isEmpty() {
        return this.piece == null;
    }

    public void shootAt(Tile[][] b, int targetX, int targetY) {
        b[targetX][targetY].setPiece(new Piece(2));
    }

    public boolean moveIfLegal(Tile[][] b, int newX, int newY) {
        if(b[newX][newY].piece == null) {//checkIfEmpty
            if(newX == oldX && newY != oldY) {//checkIfStraightLine
                if(newY < oldY) {//moveUp
                    for(int i = oldY - 1; i > newY; i--) {
                        if (!b[oldX][i].isEmpty()) return false; //path blocked by wall/amazon
                    }
                }
                else if(newY > oldY) {//moveDown
                    for(int i = oldY + 1; i < newY; i++) {
                        if (!b[oldX][i].isEmpty()) return false; //path blocked by wall/amazon
                    }
                }
                b[oldX][oldY].movePiece(b, newX, newY);
                return true;
            }
            else if(newX != oldX && newY == oldY) {
                if(newX < oldX) {//moveLeft
                    for(int i = oldX - 1; i > newX; i--) {
                        if (!b[i][oldY].isEmpty()) return false; //path blocked by wall/amazon
                    }
                }
                else if(newX > oldX) {//moveRight
                    for(int i = oldX + 1; i < newX; i++) {
                        if (!b[i][oldY].isEmpty()) return false; //path blocked by wall/amazon
                    }
                }
                b[oldX][oldY].movePiece(b, newX, newY);
                return true;
            }
            else if(Math.abs(newX-oldX) == Math.abs(newY-oldY)) {//checkIfDiagonal
                int xd, yd;
                if(newX > oldX) xd = 1;
                else xd = -1;
                if(newY > oldY) yd = 1;
                else yd = -1;

                int i = oldX + xd;
                int j = oldY + yd;
                while(i != newX && j != newY) {
                    if (!b[i][j].isEmpty()) return false; //path blocked by wall/amazon
                    i += xd;
                    j += yd;
                }
                b[oldX][oldY].movePiece(b, newX, newY);
                return true;
            }
        } return false;
    }

    public boolean shootIfLegal(Tile[][] b, int newX, int newY) {
        if(b[newX][newY].piece == null) {//checkIfEmpty
            if(newX == oldX && newY != oldY) {//checkIfStraightLine
                if(newY < oldY) {//moveUp
                    for(int i = oldY - 1; i > newY; i--) {
                        if (!b[oldX][i].isEmpty()) return false; //path blocked by wall/amazon
                    }
                }
                else if(newY > oldY) {//moveDown
                    for(int i = oldY + 1; i < newY; i++) {
                        if (!b[oldX][i].isEmpty()) return false; //path blocked by wall/amazon
                    }
                }
                b[oldX][oldY].shootAt(b, newX, newY);
                return true;
            }
            else if(newX != oldX && newY == oldY) {
                if(newX < oldX) {//moveLeft
                    for(int i = oldX - 1; i > newX; i--) {
                        if (!b[i][oldY].isEmpty()) return false; //path blocked by wall/amazon
                    }
                }
                else if(newX > oldX) {//moveRight
                    for(int i = oldX + 1; i < newX; i++) {
                        if (!b[i][oldY].isEmpty()) return false; //path blocked by wall/amazon
                    }
                }
                b[oldX][oldY].shootAt(b, newX, newY);
                return true;
            }
            else if(Math.abs(newX-oldX) == Math.abs(newY-oldY)) {//checkIfDiagonal
                int xd, yd;
                if(newX > oldX) xd = 1;
                else xd = -1;
                if(newY > oldY) yd = 1;
                else yd = -1;

                int i = oldX + xd;
                int j = oldY + yd;
                while(i != newX && j != newY) {
                    if (!b[i][j].isEmpty()) return false; //path blocked by wall/amazon
                    i += xd;
                    j += yd;
                }
                b[oldX][oldY].shootAt(b, newX, newY);
                return true;
            }
        }
        return false;
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
                this.oldX = (int) (e.getSceneX() / Tile.TILE_SIZE);
                this.oldY = (int) (e.getSceneY() / Tile.TILE_SIZE);
            }
        });
        setOnMouseReleased(e -> {
            if(e.getSceneX() < 0 || e.getSceneY() < 0) return; //top bar / left side bugfix
            int newX = (int) (e.getSceneX() / Tile.TILE_SIZE);
            int newY = (int) (e.getSceneY() / Tile.TILE_SIZE);
            if(newX == oldX && newY == oldY) return; //not moved
            if(newX < 0 || newY < 0 || newX >= b.length || newY >= b.length) return; //mouse released out of window
        });
    }

}
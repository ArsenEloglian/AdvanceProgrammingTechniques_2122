package amazons;

import javafx.fxml.FXML;
import javafx.scene.Group;
import javafx.scene.layout.GridPane;
public class AmazonsGame {

    public static final int WIDTH = 10; //Board's Width
    public static final int HEIGHT = 10; //Board's Height

    public GridPane Board;
    public Tile[][] b = new Tile[WIDTH][HEIGHT];
    private Group tileGroup = new Group();

    @FXML
    public void initialize() {
        Board.getChildren().addAll(tileGroup);

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                Tile tile = new Tile(b,(x + y) % 2 == 0, x, y);
                b[x][y] = tile;
                tileGroup.getChildren().add(tile);
            }
        }
        //init the black pieces
        b[3][0].setPiece(new Piece(1));
        b[6][0].setPiece(new Piece(1));
        b[0][3].setPiece(new Piece(1));
        b[9][3].setPiece(new Piece(1));
        //init the white pieces
        b[3][9].setPiece(new Piece(0));
        b[6][9].setPiece(new Piece(0));
        b[0][6].setPiece(new Piece(0));
        b[9][6].setPiece(new Piece(0));

        //if (b[3][0].hasPiece()) System.out.println("[3][0] contains a piece!");
        //b[3][0].getPiece() System.out.println("Maybe this will be useful!");
        b[3][0].movePiece(b, 9, 9);
        b[3][0].shootAt(b, 8, 8);
        b[3][0].shootAt(b, 7, 7);
    }
}

package amazons;

import javafx.fxml.FXML;
import javafx.scene.Group;
import javafx.scene.layout.GridPane;

public class AmazonsGame {

    public static final int WIDTH = 10; //Board's Width
    public static final int HEIGHT = 10; //Board's Height

    public GridPane Board;
    private Group tileGroup = new Group();

    @FXML
    public void initialize() {
        Board.getChildren().addAll(tileGroup);

        for(int y = 0; y < HEIGHT; y++) {
            for(int x = 0; x < WIDTH; x++) {
                Tile tile = new Tile((x + y) % 2 == 0, x, y);
                tileGroup.getChildren().add(tile);
            }
        }
    }

}

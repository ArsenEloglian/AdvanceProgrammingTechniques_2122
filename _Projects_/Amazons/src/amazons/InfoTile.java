package amazons;

import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;

public class InfoTile extends StackPane {
    private final Text text;
    private final Rectangle rectangle;

    public InfoTile(String letter, int x, int y) {
        this.text = new Text(x, y, letter);
        rectangle = new Rectangle(x, y);
        rectangle.setWidth(Main.TILE_SIZE);
        rectangle.setHeight(Main.TILE_SIZE);
        rectangle.setFill(Color.GAINSBORO);
        relocate(x * Main.TILE_SIZE, y * Main.TILE_SIZE);

        getChildren().addAll(rectangle, this.text);
    }

    public InfoTile(int number, int x, int y) {
        this.text = new Text(x, y, String.valueOf(number));
        rectangle = new Rectangle(x, y);
        rectangle.setWidth(Main.TILE_SIZE);
        rectangle.setHeight(Main.TILE_SIZE);
        rectangle.setFill(Color.GAINSBORO);
        relocate(x * Main.TILE_SIZE, y * Main.TILE_SIZE);

        getChildren().addAll(rectangle, this.text);
    }
}

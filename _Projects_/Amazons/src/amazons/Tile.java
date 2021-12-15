package amazons;

import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class Tile extends Rectangle {

    public Tile(boolean light, int x, int y) {
        setWidth(Main.TILE_SIZE);
        setHeight(Main.TILE_SIZE);
        //int offset = Main.TILE_SIZE;
        relocate(x * Main.TILE_SIZE, y * Main.TILE_SIZE);
        setFill(light ? Color.valueOf("#ffce9e") : Color.valueOf("#D18B47"));
    }
}

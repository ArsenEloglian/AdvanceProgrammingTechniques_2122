package amazons;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.StackPane;

public class Piece extends StackPane {
    public int type; //0 = white, 1 = black
    public ImageView image;

    public Piece(int type) {
        this.type = type;
        if (type == 0) {
            this.image = new ImageView(new Image("file:res/pieceW.png"));
        }
        else if (type == 1) {
            this.image = new ImageView(new Image("file:res/pieceB.png"));
        }
        else if (type == 2) {
            this.image = new ImageView(new Image("file:res/wall.png"));
        }

        getChildren().addAll(image);
    }
}

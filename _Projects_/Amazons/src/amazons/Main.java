package amazons;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class Main extends Application {

    public static final int TILE_SIZE = 50;
    public static final int WIDTH = 10;
    public static final int HEIGHT = 10;

    private Group tileGroup = new Group();
    private Group infoTileGroup = new Group();

    private Parent createContent() {
        Pane root = new Pane();
        root.setPrefSize((WIDTH + 1) * TILE_SIZE, (HEIGHT + 1) * TILE_SIZE);
        root.getChildren().addAll(tileGroup, infoTileGroup);

        for(int y = 0; y < HEIGHT; y++) {
            for(int x = 0; x < WIDTH; x++) {
                Tile tile = new Tile((x + y) % 2 == 0, x, y);
                tileGroup.getChildren().add(tile);
            }
        }

        for(int x = 0; x < WIDTH; x++) {
            InfoTile tile = new InfoTile(Character.toString('A' + x), x, HEIGHT);
            infoTileGroup.getChildren().add(tile);
        }
        for(int y = 0; y < HEIGHT; y++) {
            InfoTile tile = new InfoTile(HEIGHT - y, WIDTH, y);
            infoTileGroup.getChildren().add(tile);
        }
        return root;
    }

    @Override
    public void start(Stage primaryStage) throws Exception{
        //Parent root = FXMLLoader.load(getClass().getResource("Amazons.fxml"));
        Scene scene = new Scene(createContent());
        primaryStage.setTitle("Game of the Amazons");
        primaryStage.setScene(scene);
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}

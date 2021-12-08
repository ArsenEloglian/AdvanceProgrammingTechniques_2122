package amazons;

import amazons.InfoTile;
import amazons.Tile;
import com.sun.media.jfxmediaimpl.platform.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class AmazonsMenu {

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

    public void startGame(ActionEvent actionEvent) {
        try {
           // FXMLLoader loader = new FXMLLoader(getClass().getResource("Amazons.fxml"));
            //Parent root1 = (Parent) loader.load();
            Stage stage = new Stage();
            stage.setTitle("Game of the Amazons");
            Scene scene = new Scene(createContent());
            stage.setScene(scene);
            stage.show();

            final Node source = (Node) actionEvent.getSource();
            final Stage stage1 = (Stage) source.getScene().getWindow();
            stage1.close();

        }
        catch (Exception e) {
            System.out.println("Can't open new window");
        }
    }

    public void openOptions(ActionEvent actionEvent) {

        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("Amazons_options.fxml"));
            Parent root1 = (Parent) loader.load();
            Stage stage = new Stage();
            stage.setTitle("Game of the Amazons");
            stage.setScene(new Scene(root1));
            stage.show();

            final Node source = (Node) actionEvent.getSource();
            final Stage stage1 = (Stage) source.getScene().getWindow();
            stage1.close();

        }
        catch (Exception e) {
            System.out.println("Can't open new window");
        }
    }

    public void exitGame(ActionEvent actionEvent) {
        final Node source = (Node) actionEvent.getSource();
        final Stage stage = (Stage) source.getScene().getWindow();
        stage.close();
    }
}

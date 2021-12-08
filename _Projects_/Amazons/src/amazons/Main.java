package amazons;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

//    public static final int TILE_SIZE = 50;
//    public static final int WIDTH = 10;
//    public static final int HEIGHT = 10;
//
//    private Group tileGroup = new Group();
//    private Group infoTileGroup = new Group();



    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("Amazons_menu.fxml"));
        //Scene scene = new Scene(createContent());
        Scene scene = new Scene(root);
        primaryStage.setTitle("Game of the Amazons");
        primaryStage.setScene(scene);
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}

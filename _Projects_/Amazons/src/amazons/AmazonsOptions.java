package amazons;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ComboBox;
import javafx.stage.Stage;

import java.io.IOException;

public class AmazonsOptions {

    public ComboBox modeSelect;

    String mode;
    Parent root;
    Stage stage;
    Scene scene;
    @FXML
    public void initialize() {

        modeSelect.getItems().add("HotSeat");
        modeSelect.getItems().add("vs AI");

        modeSelect.setValue("HotSeat");

        mode = "vs AI";

    }


    public void backToMenu(ActionEvent actionEvent) {

        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("Amazons_menu.fxml"));
            Parent root1 = loader.load();
            Stage stage = new Stage();
            stage.setTitle("Game of the Amazons");
            Scene scene = new Scene(root1);
            stage.setScene(scene);
            stage.show();

            final Node source = (Node) actionEvent.getSource();
            final Stage stage1 = (Stage) source.getScene().getWindow();
            stage1.close();

        }
        catch (Exception e) {
            e.printStackTrace();
        }

    }

    public void applyChanges(ActionEvent event) throws IOException {

        // save all settings

        mode = (String) modeSelect.getValue();

        FXMLLoader loader = new FXMLLoader(getClass().getResource("Amazons_menu.fxml"));
        root = loader.load();

        AmazonsMenu menuController = loader.getController();
        menuController.setGameParameters(mode,"");

        stage = new Stage();
        scene = new Scene(root);
        stage.setTitle("Game of the Amazons");
        stage.setScene(scene);

        stage.show();
        final Node source = (Node) event.getSource();
        final Stage stage1 = (Stage) source.getScene().getWindow();
        stage1.close();
    }
}

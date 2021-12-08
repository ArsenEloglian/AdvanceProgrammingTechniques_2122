package amazons;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ComboBox;
import javafx.stage.Stage;

public class AmazonsOptions {

    public ComboBox difficultSelect;

    @FXML
    public void initialize() {

        difficultSelect.getItems().add("Easy");
        difficultSelect.getItems().add("Medium");
        difficultSelect.getItems().add("Hard");

        difficultSelect.setValue("Easy");

    }


    public void backToMenu(ActionEvent actionEvent) {

        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("Amazons_menu.fxml"));
            Parent root1 = (Parent) loader.load();
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
            System.out.println("Can't open new window");
        }

    }

    public void applyChanges(ActionEvent actionEvent) {

        // save all settings

        final Node source = (Node) actionEvent.getSource();
        final Stage stage = (Stage) source.getScene().getWindow();
        stage.close();

    }
}

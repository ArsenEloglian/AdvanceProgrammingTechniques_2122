package amazons;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

public class AmazonsMenu {

    public static Stage gameStage;
    public String difficult;
    public String mode;
    public Label labelDifficult;
    public Label labelMode;
    public Parent root;
    public Scene scene;

    @FXML
    public void initialize() {
        labelDifficult.setText("Easy");
        labelMode.setText("HotSeat");

        labelMode.setVisible(false);
        labelDifficult.setVisible(false);

    }

    public void startGame(ActionEvent actionEvent) {
        try {
            if (labelMode.getText().equals("HotSeat")) {
                FXMLLoader loader = new FXMLLoader(getClass().getResource("Amazons_game.fxml"));
                root = loader.load();

                mode = labelMode.getText();
                difficult = labelDifficult.getText();

                gameStage = new Stage();

                scene = new Scene(root);
                gameStage.setTitle("Game of the Amazons");
                gameStage.setScene(scene);
                gameStage.setResizable(false);
                gameStage.show();

                final Node source = (Node) actionEvent.getSource();
                final Stage stage = (Stage) source.getScene().getWindow();
                stage.close();

            }
            else {
                FXMLLoader loader = new FXMLLoader(getClass().getResource("Amazons_game_ai.fxml"));
                root = loader.load();
                mode = labelMode.getText();
                difficult = labelDifficult.getText();
                gameStage = new Stage();

                scene = new Scene(root);
                gameStage.setTitle("Game of the Amazons");
                gameStage.setScene(scene);
                gameStage.setResizable(false);
                gameStage.show();

                final Node source = (Node) actionEvent.getSource();
                final Stage stage = (Stage) source.getScene().getWindow();
                stage.close();
            }
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void openOptions(ActionEvent actionEvent) {

        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("Amazons_options.fxml"));
            Parent root1 = loader.load();
            Stage stage = new Stage();
            stage.setTitle("Game of the Amazons");
            stage.setScene(new Scene(root1));
            stage.show();

            final Node source = (Node) actionEvent.getSource();
            final Stage stage1 = (Stage) source.getScene().getWindow();
            stage1.close();

        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void exitGame(ActionEvent actionEvent) {
        final Node source = (Node) actionEvent.getSource();
        final Stage stage = (Stage) source.getScene().getWindow();
        stage.close();
    }

    public void setGameParameters(String newMode, String newDifficult) {
        labelDifficult.setText(newDifficult);
        labelMode.setText(newMode);
        labelMode.setVisible(false);
        labelDifficult.setVisible(false);
    }

}
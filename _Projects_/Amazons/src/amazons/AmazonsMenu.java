package amazons;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class AmazonsMenu {

    public static Stage gameStage = new Stage();

    public void startGame(ActionEvent actionEvent) {
        try {
            Parent game = FXMLLoader.load(getClass().getResource("Amazons_game.fxml"));
            gameStage.setTitle("Game of the Amazons");
            gameStage.setScene(new Scene(game));
            gameStage.setResizable(false);
            gameStage.show();

            final Node source = (Node) actionEvent.getSource();
            final Stage stage = (Stage) source.getScene().getWindow();
            stage.close();
        }
        catch (Exception e) {
            //System.out.println("Can't open new window");
            e.printStackTrace();
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
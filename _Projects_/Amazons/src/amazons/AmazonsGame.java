package amazons;

import javafx.animation.AnimationTimer;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class AmazonsGame {

    public static final int WIDTH = 10; //Board's Width
    public static final int HEIGHT = 10; //Board's Height

    public GridPane Board;
    public Tile[][] b = new Tile[WIDTH][HEIGHT];
    public Label turn;
    private Group tileGroup = new Group();

    public int player;
    int oldX;       // old piece positions
    int oldY;

    int newX;       //new piece positions
    int newY;

    int targetX;    //target for shoot
    int targetY;

    int activePieceX;
    int activePieceY;

    boolean shot = false;
    boolean move = false;

    GameLogic game = new GameLogic();

    @FXML
    ListView<String> list;
    @FXML
    Rectangle turnColor;

    public Label cord;
    public Label whatDo;
    public Label currentTime;

    AnimationTimer animationTimer;

    public Button exitButton;
    public Button restartButton;
    ButtonType restart = new ButtonType("Play again");
    ButtonType exit = new ButtonType("Exit to menu");
    Dialog<ButtonType> dialog = new Dialog<>();

    @FXML
    public void initialize() {
        turn.textProperty().addListener((ov, t, t1) -> {
            if(game.getTurnsInt() % 2 == 1) {
                turnColor.setFill(Color.WHITE);
            }
            else {
                turnColor.setFill(Color.BLACK);
            }
        });
        dialog.setTitle("Game Over...");
        dialog.getDialogPane().getButtonTypes().addAll(restart, exit);

        long startTime = System.currentTimeMillis();

        animationTimer = new AnimationTimer() {
            @Override
            public void handle(long now) {
                long elapsedMillis = System.currentTimeMillis() - startTime;
                currentTime.setText(Long.toString(elapsedMillis / 1000));
            }
        };
        animationTimer.start();
        Board.getChildren().addAll(tileGroup);

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                Tile tile = new Tile(b,(x + y) % 2 == 0, x, y);
                b[x][y] = tile;
                tileGroup.getChildren().add(tile);
            }
        }
        //init the black pieces
        b[3][0].setPiece(new Piece(1));
        b[6][0].setPiece(new Piece(1));
        b[0][3].setPiece(new Piece(1));
        b[9][3].setPiece(new Piece(1));
        //init the white pieces
        b[3][9].setPiece(new Piece(0));
        b[6][9].setPiece(new Piece(0));
        b[0][6].setPiece(new Piece(0));
        b[9][6].setPiece(new Piece(0));


        turn.setText(game.getTurns());

        player = 0;



    }

    public void getPieceCords(MouseEvent e) {

        int x = (int) e.getSceneX();
        int y = (int) e.getSceneY();
        x/=Tile.TILE_SIZE;
        y/=Tile.TILE_SIZE;
        if (b[x][y].hasPiece()) {
            oldX = x;
            oldY = y;
        }
    }

    public void getNewCords(MouseEvent e) {
        int x = (int) e.getSceneX();
        int y = (int) e.getSceneY();
        x/=Tile.TILE_SIZE;
        y/=Tile.TILE_SIZE;
        if (move && !shot) {  // check if movemement was made
            newX = x;
            newY = y;

            Piece piece = b[oldX][oldY].getPiece();
            if (player != piece.type) return;

            shoot();    // shooting
            if (shot) {

                shot = false; // setting flags for new turn and swap players
                move = false;

                game.newTurn();
                turn.setText(game.getTurns());
                if (player == 0) player = 1;
                else player = 0;
            }

        };

        Piece piece = b[oldX][oldY].getPiece(); //  making movement
        if (piece == null) return;
        if (player != piece.type) return;
                if (move) return;
                //if (shot == false) return;
                newX = x;
                newY = y;
                movePiece();
                activePieceX = newX;
                activePieceY = newY;
    }

    public void shootDestination(MouseEvent e) {

        if(shot) return;

        int x = (int) e.getSceneX();
        int y = (int) e.getSceneY();
        x/=Tile.TILE_SIZE;
        y/=Tile.TILE_SIZE;
        targetY = y;
        targetX = x;

        b[newX][newY].shootIfLegal(b,targetX,targetY);
        System.out.println("costam");
        shot = true;

    }

    public void movePiece() {

        Piece piece = b[oldX][oldY].getPiece();
        if (player != piece.type) return;

        if (move) return;
        if (!b[oldX][oldY].moveIfLegal(b, newX, newY)) { // checking movement restrictions
            // do nothing
        }
        else {                                                 // if ok move piece
            list.getItems().add(0,(char)(oldX + 97) + "" + oldY + "" + (char)(newX + 97) + "" + newY);
            whatDo.setText("Shoot");
            move = true;
            shot = false;
            checkMoves(); //temporary
        }
    }
    public void shoot() {

        Piece piece = b[oldX][oldY].getPiece();
        if (player != piece.type) return;

        if (shot == true) return;

        if (activePieceX != oldX || activePieceY != oldY){
            System.out.println("Old X: " + oldX + " Y: " + oldY);
            System.out.println("Act X: " + activePieceX + " Y: " + activePieceY);
            return;
        }

        if (!b[oldX][oldY].shootIfLegal(b, newX, newY)) {// checking shooting restrictions
            // do nothing
        }
        else {                                                  // if ok shoot
            String temp = list.getItems().get(0) + " -> " + (char)(newX + 97) + "" + newY;;
            list.getItems().set(0, temp);
            whatDo.setText("Move");
            shot = true;
            move = false;
            checkMoves(); //temporary
        }
    }
    public void getHover(MouseEvent e) {
        int x = (int) e.getSceneX();
        int y = (int) e.getSceneY();
        x/=Tile.TILE_SIZE;
        y/=Tile.TILE_SIZE;
        cord.setText((char)(x + 97) + "" + y);
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
    public void restart(ActionEvent actionEvent) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("Amazons_game.fxml"));
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

    public void checkMoves() {
        List<Pair<Integer, Integer>> whitePieces = new ArrayList<>();
        List<Pair<Integer, Integer>> blackPieces = new ArrayList<>();
        for(int y = 0; y < HEIGHT; y++) {
            for(int x = 0; x < WIDTH; x++) {
                if(b[x][y].getPiece() == null) {
                    continue;
                }
                else if(b[x][y].getPiece().type == 0) {
                    whitePieces.add(new Pair<>(x, y));
                }
                else if(b[x][y].getPiece().type == 1){
                    blackPieces.add(new Pair<>(x, y));
                }
            }
        }

        if(!canPlayerMove(whitePieces)) {
            animationTimer.stop();
            dialog.setHeaderText("Black won!");
            dialog.setGraphic(new ImageView(new Image(this.getClass().getResourceAsStream("res/pieceB.png"))));
            Optional<ButtonType> result = dialog.showAndWait();
            if(result.isPresent() && result.get() == restart) {
                restartButton.fireEvent(new ActionEvent());
            }
            else {
                exitButton.fireEvent(new ActionEvent());
            }
        }
        if(!canPlayerMove(blackPieces)) {
            animationTimer.stop();
            dialog.setHeaderText("White won!");
            dialog.setGraphic(new ImageView(new Image(this.getClass().getResourceAsStream("res/pieceW.png"))));
            Optional<ButtonType> result = dialog.showAndWait();
            if(result.isPresent() && result.get() == restart) {
                restartButton.fireEvent(new ActionEvent());
            }
            else {
                exitButton.fireEvent(new ActionEvent());
            }
        }
    }

    boolean canPlayerMove(List<Pair<Integer, Integer>> pieceList) {
        boolean canMove = false;
        for(int k = 0; k < 4; k++) {
            int checkX = pieceList.get(k).getKey();
            int checkY = pieceList.get(k).getValue();

            for(int i = checkX-1; i <= checkX+1; i++) {
                for(int j = checkY-1; j <= checkY+1; j++) {
                    if((i != checkX || j != checkY) && i >= 0 && j >= 0 && i < WIDTH && j < HEIGHT) { //ignore the center tile and out of bounds elements
                        if(b[i][j].isEmpty()) canMove = true;
                    }
                }
            }
        }
        return canMove;
    }
}

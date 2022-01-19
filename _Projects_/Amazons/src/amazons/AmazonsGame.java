package amazons;

import javafx.application.Platform;
import javafx.beans.InvalidationListener;
import javafx.beans.Observable;
import javafx.animation.AnimationTimer;
import javafx.beans.InvalidationListener;
import javafx.beans.Observable;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
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
    public Label timeLabel;
    public Button starttime;
    public Label turn;
    public Label color;
    public Label xandy;
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

    boolean whiteCanMove = true;
    boolean blackCanMove = true;
    AnimationTimer animationTimer;

    public Button exitButton;
    public Button restartButton;
    ButtonType restart = new ButtonType("Play again");
    ButtonType exit = new ButtonType("Exit to menu");
    Dialog<ButtonType> dialog = new Dialog<>();

    @FXML
    public void initialize() {
        turn.textProperty().addListener(new ChangeListener<String>() {
            @Override
            public void changed(ObservableValue<? extends String> ov, String t, String t1) {
                if(game.getTurnsInt() % 2 == 1) {
                    turnColor.setFill(Color.WHITE);
                }
                else {
                    turnColor.setFill(Color.BLACK);
                }
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

        Piece bialy=b[9][6].getPiece();
        Piece czarny=b[3][0].getPiece();

//        System.out.println("Niby bialy " + bialy.type);
//        System.out.println("Niby czarny " + czarny.type);
        //if (b[3][0].hasPiece()) System.out.println("[3][0] contains a piece!");
        //b[3][0].getPiece() System.out.println("Maybe this will be useful!");
//        b[3][0].movePiece(b, 9, 9);
//        b[3][0].shootAt(b, 8, 8);
//        b[3][0].shootAt(b, 7, 7);

        turn.setText(game.getTurns());

       // gameLoop();
        player = 0;
        //shot = false;

    }

    public void startTimer() {
        game.newTurn();
        turn.setText(game.getTurns());
    }

    public void getPieceCords(MouseEvent e) {

        int x = (int) e.getSceneX();
        int y = (int) e.getSceneY();
        x/=50;
        y/=50;
       // Piece piece = b[oldX][oldY].getPiece();
        if (b[x][y].hasPiece()) {
            oldX = x;
            oldY = y;
        }
        else {
            return;
        }
       // System.out.println(x + " " + y);
    }

    public void getNewCords(MouseEvent e) {
        int x = (int) e.getSceneX();
        int y = (int) e.getSceneY();
        x/=50;
        y/=50;
        if (move == true && shot == false) {  // check if movemement was made
            newX = x;
            newY = y;

            Piece piece = b[oldX][oldY].getPiece();
            if (player != piece.type) return;

            shoot();    // shooting
            if (shot == true) {

                shot = false; // setting flags for new turn and swap players
                move = false;



                game.newTurn();
                turn.setText(game.getTurns());
                if (player == 0) player = 1;
                else player = 0;
            }

        };
//        newX = x;
//        newY = y;

        Piece piece = b[oldX][oldY].getPiece(); //  making movement
        if (piece == null) return;
        if (player != piece.type) return;
                if (move == true) return;
                //if (shot == false) return;
                newX = x;
                newY = y;
                movePiece();
                activePieceX = newX;
                activePieceY = newY;
    }

    public void shootDestination(MouseEvent e) {

        if(shot == true) return;

        int x = (int) e.getSceneX();
        int y = (int) e.getSceneY();
        x/=50;
        y/=50;
        targetY = y;
        targetX = x;
        //b[newX][oldY].shootIfLegal(b,x,y);
        //shoot();
        //shoot = true;
        //System.out.println("Piece position: " + newX + " " + newY);

        b[newX][newY].shootIfLegal(b,targetX,targetY);
        System.out.println("costam");
        shot = true;

    }

//    public void movePiece() {
//
//        Piece piece = b[oldX][oldY].getPiece();
//        if (player != piece.type) return;
//
//        if (move == true) return;
//        if (b[oldX][oldY].moveIfLegal(b,newX,newY) == false) { // checking movement restrictions
//
//            return;
//        }
//        else {                                                 // if ok move piece
//
//            move = true;
//            shot = false;
//
//        }
//    }


    public void movePiece() {

        Piece piece = b[oldX][oldY].getPiece();
        if (player != piece.type) return;

        if (move == true) return;
        if (b[oldX][oldY].moveIfLegal(b,newX,newY) == false) { // checking movement restrictions

            return;
        }
        else {                                                 // if ok move piece
            //list.getItems().add(0,"[" + oldX + "][" + oldY + "] movedTo [" + newX + "][" + newY + "]");
            list.getItems().add(0,(char)(oldX + 97) + "" + oldY + "" + (char)(newX + 97) + "" + newY);
            whatDo.setText("Shoot");
            move = true;
            shot = false;
            checkMoves(); //temporary
        }
    }
    public void shoot() {

        //if (shot == true) return;

       // System.out.println("Piece position: " + newX + " " + newY);
        Piece piece = b[oldX][oldY].getPiece();
        if (player != piece.type) return;

        if (shot == true) return;

        if (activePieceX != oldX || activePieceY != oldY){
            System.out.println("Old X: " + oldX + " Y: " + oldY);
            System.out.println("Act X: " + activePieceX + " Y: " + activePieceY);
            return;
        }

        if (b[oldX][oldY].shootIfLegal(b,newX,newY) == false) { // checking shooting restrictions
            //System.out.println("Nope");
            return;
        }

        else {                                                  // if ok shoot
            //shot = true;
            //list.getItems().add(0,"[" + oldX + "][" + oldY + "] shotAt [" + newX + "][" + newY + "]");
            String temp = list.getItems().get(0) + " -> " + (char)(newX + 97) + "" + newY;;
            list.getItems().set(0, temp);
            whatDo.setText("Move");
            shot = true;
            move = false;
           // System.out.println("Strzelił");
            checkMoves(); //temporary
        }
    }
    public void setActivePlayer(int active) {

        player = active;

    }
    public void getHover(MouseEvent e) {
        int x = (int) e.getSceneX();
        int y = (int) e.getSceneY();
        x/=50;
        y/=50;
        cord.setText((char)(x + 97) + "" + y);
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
    public void restart(ActionEvent actionEvent) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("Amazons_game.fxml"));
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
            //System.out.println("Can't open new window");
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

        //System.out.println("White can move " + canPlayerMove(whitePieces));
        //System.out.println("Black can move " + canPlayerMove(blackPieces) + "\n");

        if(!canPlayerMove(whitePieces)) {
            animationTimer.stop();
            dialog.setHeaderText("Black won!");
            dialog.setGraphic(new ImageView(new Image("file:res/pieceB.png")));
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
            dialog.setGraphic(new ImageView(new Image("file:res/pieceW.png")));
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

//    public boolean gameLoop() {
//        System.out.println("gra sie zaczęła");
//
//        boolean whiteTurn = true;
//        boolean blackTurn = false;
//
////        int x;
////        int y;
//        //   int oldX;
//        //  int oldY;
//
//        // while (game.isGameEnd() == false) {
//        System.out.println("gra sie toczy...");
//        int player = 0;
//        if (player == 0) {    //  white player makes the move
//
//            System.out.println("Ruch białych");
//
//            Board.getChildren().forEach(item ->
//                    //set on mouse pressed a potem released
//                    item.setOnMousePressed(event -> {
//                        int oldX = (int) event.getX();
//                        int oldY = (int) event.getY();
//                        //xandy.setText(String.valueOf(x/50 + " " + y/50));
//                        oldX/= 50;
//                        oldY/= 50;
//
//                        if (b[oldY][oldX].hasPiece()) {
//
//                            Piece piece = b[oldY][oldX].getPiece();
//                            if (piece.type == 0) {
//                                int finalOldY = oldY;
//                                int finalOldX = oldX;
//                                item.setOnMouseReleased(e -> {
//                                    int x = (int) e.getX();
//                                    int y = (int) e.getY();
//
//                                    x/= 50;
//                                    y/= 50;
//
//                                    System.out.println(piece.type);
//                                    System.out.println("Rusza sie biały");
//                                    b[finalOldX][finalOldY].moveIfLegal(b, x, y); // piece moved to new location
//
//                                    xandy.setText(x + " " +y);
//
//                                    int finalY = y;
//                                    int finalX = x;
//
//                                    finalY/=50;
//                                    finalX/=50;
//                                    int finalY1 = finalY;
//                                    int finalX1 = finalX;
//                                    item.setOnMousePressed(shoot -> {
//                                        int shootX = (int) shoot.getX();
//                                        int shootY = (int) shoot.getY();
//                                        shootY/=50;
//                                        shootX/=50;
//                                        b[finalX1][finalY1].shootIfLegal(b,shootX,shootY);
//
//                                    });
//                                });
//                            }
//                        }
//                    }));
//            player = 1;
//        }
//        else {                                      // black player makes the move
//            System.out.println("Ruch czarnych");
//
//            Board.getChildren().forEach(item ->
//                    //set on mouse pressed a potem released
//                    item.setOnMousePressed(event -> {
//                        int oldX = (int) event.getX();
//                        int oldY = (int) event.getY();
//                        //xandy.setText(String.valueOf(x/50 + " " + y/50));
//                        oldX/= 50;
//                        oldY/= 50;
//
//                        if (b[oldY][oldX].hasPiece()) {
//
//                            Piece piece = b[oldY][oldX].getPiece();
//                            if (piece.type == 1) {
//                                int finalOldY = oldY;
//                                int finalOldX = oldX;
//                                item.setOnMouseReleased(e -> {
//                                    int x = (int) e.getX();
//                                    int y = (int) e.getY();
//
//                                    x/= 50;
//                                    y/= 50;
//
//                                    System.out.println(piece.type);
//                                    System.out.println("Rusza sie biały");
//                                    b[finalOldX][finalOldY].moveIfLegal(b, x, y); // piece moved to new location
//
//                                    xandy.setText(x + " " +y);
//
//                                    int finalY = y;
//                                    int finalX = x;
//
//                                    finalY/=50;
//                                    finalX/=50;
//                                    int finalY1 = finalY;
//                                    int finalX1 = finalX;
//                                    item.setOnMousePressed(shoot -> {
//                                        int shootX = (int) shoot.getX();
//                                        int shootY = (int) shoot.getY();
//                                        shootY/=50;
//                                        shootX/=50;
//                                        b[finalX1][finalY1].shootIfLegal(b,shootX,shootY);
//                                    });
//                                });
//                            }
//                        }
//                    }));
//            game.newTurn();
//            player = 0;
//        }
//
//
//
//        // }
//
//        return game.isGameEnd();
//    }
}

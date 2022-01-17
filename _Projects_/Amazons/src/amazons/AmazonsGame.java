package amazons;

import javafx.beans.InvalidationListener;
import javafx.beans.Observable;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.Group;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;

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
    public void initialize() {
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

            }
            if (player == 0) player = 1;
            else player = 0;
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

    public void movePiece() {

        Piece piece = b[oldX][oldY].getPiece();
        if (player != piece.type) return;

        if (move == true) return;
        if (b[oldX][oldY].moveIfLegal(b,newX,newY) == false) { // checking movement restrictions

            return;
        }
        else {                                                 // if ok move piece

            move = true;
            shot = false;

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
            shot = true;
            move = false;
           // System.out.println("Strzelił");
        }
    }
    public void setActivePlayer(int active) {

        player = active;

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

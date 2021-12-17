package com.example.firstproject;

import java.awt.*;

import static com.example.firstproject.Global.*;

public class Plansza {
    String[][] arr;
    Player player1;
    Player player2;
    int posiblesMoves;
    int size;

    void setPoint(Point p, String symbol) {
        arr[(int) p.getX()][(int) p.getY()] = symbol;
    }

    Plansza(int wielkosc) {
        size = wielkosc;
        arr =initializeArray();
        player1 = new Player(2, 3, 2, 8, queen1);
        player2 = new Player(8, 2, 7, 9, queen2);

        setPoint(player1.queen1, queen1);
        setPoint(player1.queen2, queen1);
        setPoint(player2.queen1, queen2);
        setPoint(player2.queen2, queen2);
        posiblesMoves = 0;
    }

    void posiblesMovesup() {
        posiblesMoves++;
    }

    void posiblesMovesreset() {
        posiblesMoves = 0;
    }

    public boolean isPlayerHaveMove(Player player) {
        String[][] tmp = initializeArray();
        checkPosibleMovesForPlayer(player, tmp);
        if (posiblesMoves > 0) {
            posiblesMovesreset();
            return true;
        } else {
            posiblesMovesreset();
            return false;
        }

    }

    private void checkPosibleMovesForPlayer(Player player, String[][] tmp) {
        checkposiblemoves(player.queen1, tmp, player);
        checkposiblemoves(player.queen2, tmp, player);
    }

    private void checkposiblemoves(Point queen, String[][] tmp, Player player) {
        tmp[(int) queen.getX()][(int) queen.getY()] = player.getSymbol();
        checkLinePosibleMoves(tmp, queen, 1, 1);
        checkLinePosibleMoves(tmp, queen, 1, 0);
        checkLinePosibleMoves(tmp, queen, 1, -1);
        checkLinePosibleMoves(tmp, queen, 0, 1);
        checkLinePosibleMoves(tmp, queen, 0, -1);
        checkLinePosibleMoves(tmp, queen, -1, 1);
        checkLinePosibleMoves(tmp, queen, -1, 0);
        checkLinePosibleMoves(tmp, queen, -1, -1);
        //return  tmp;
    }

    private void checkLinePosibleMoves(String[][] tmp, Point quenn, int rowmove, int columnmove) {
        int row, column;
        switch (rowmove) {
            case -1 -> row = (int) quenn.getX() - 1;
            case 0 -> row = (int) quenn.getX();
            default -> row = (int) quenn.getX() + 1;
        }
        switch (columnmove) {
            case -1 -> column = (int) quenn.getY() - 1;
            case 0 -> column = (int) quenn.getY();
            default -> column = (int) quenn.getY() + 1;
        }
        while ((row >= 0 && row < size) && (column >= 0 && column < size)) {
            if (!arr[row][column].equals(queen1) &&
                    !arr[row][column].equals(queen2) &&
                    !arr[row][column].equals(block)) {
                tmp[row][column] = "1";
                posiblesMovesup();
            } else {
                break;
            }
            switch (rowmove) {
                case 1 -> row++;
                case -1 -> row--;
            }
            switch (columnmove) {
                case 1 -> column++;
                case -1 -> column--;
            }
        }
    }

    public boolean ifMoveIsPosible(Point wspolrzedne, Point wspolrzedneq, Player player) {
        String[][] tmp = initializeArray();
        checkposiblemoves(wspolrzedneq, tmp, player);
        posiblesMovesreset();
        return tmp[(int) wspolrzedne.getX()][(int) wspolrzedne.getY()].equals("1");
    }

    public int getSize() {
        return size;
    }

    public boolean ifBlockIsPosible(Point blockPoint, Point quennMovePoint, Player player) {
        String[][] tmp = initializeArray();
        checkposiblemoves(quennMovePoint, tmp, player);
        posiblesMovesreset();
        return tmp[(int) blockPoint.getX()][(int) blockPoint.getY()].equals("1");
    }
    public boolean ifQueenHaveMove(Point queenPoint, Player player) {
        String[][] tmp = initializeArray();
        checkposiblemoves(queenPoint, tmp, player);
        if (posiblesMoves > 0) {
            posiblesMovesreset();
            return true;
        } else {
            posiblesMovesreset();
            return false;
        }
    }

    public boolean checkIsPointIsQueen(Point wspolrzedne, Player player) {
        Point[] quenns = player.getQuenns();
        return quenns[0].equals(wspolrzedne) || quenns[1].equals(wspolrzedne);
    }
    public void movequeen(Point quennOldPoint, Point quennNewPoint, Player player) {
        if (player.equals(player1)) {
            player1.changePoint(quennOldPoint, quennNewPoint);
        } else {
            player2.changePoint(quennOldPoint, quennNewPoint);
        }
        changeQueenPoint(quennOldPoint, quennNewPoint, player);
    }
    private void changeQueenPoint(Point quennOldPoint, Point quennNewPoint, Player player) {
        arr[(int) quennOldPoint.getX()][(int) quennOldPoint.getY()] = "0";
        arr[(int) quennNewPoint.getX()][(int) quennNewPoint.getY()] = player.getSymbol();
    }
    private String[][] initializeArray(){
        String[][] tmp = new String[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                tmp[i][j] = "0";
            }
        }
        return tmp;
    }
}

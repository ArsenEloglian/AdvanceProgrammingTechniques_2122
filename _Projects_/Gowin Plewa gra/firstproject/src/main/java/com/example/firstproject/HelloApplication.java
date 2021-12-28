package com.example.firstproject;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.awt.Point;

import java.io.IOException;
import java.util.Scanner;


public class HelloApplication extends Application {

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 320, 240);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
        Plansza arr = new Plansza(10);
        //gra
        // player1
        while (true) {
            System.out.println("Gracz 1");
            if (!playerMove(arr, arr.player1)) {
                System.out.println("Gracz 2 wygrał");
                break;
            }
            System.out.println("Gracz 2");
            if (!playerMove(arr, arr.player2)) {
                System.out.println("Gracz 1 wygrał");
                break;
            }
        }

    }

    public boolean playerMove(Plansza arr, Player player) {
        printArray(arr.arr);
        if (!arr.isPlayerHaveMove(player)) {
            return false;
        }
        System.out.print("KRÓLOWA: ");
        Point quennPoint;
        do {
            quennPoint = podaj_wspolrzedne();
        } while (!arr.checkIsPointIsQueen(quennPoint, player) && !arr.ifQueenHaveMove(quennPoint, player));
        System.out.print("RUCH KRÓLOWEJ: ");
        Point quennMovePoint;
        do {
            quennMovePoint = podaj_wspolrzedne();
        } while (!arr.ifMoveIsPosible(quennMovePoint, quennPoint, player));
        arr.movequeen(quennPoint, quennMovePoint, player);
        printArray(arr.arr);
        System.out.print("BLOK: ");
        Point blockPoint;
        do {
            blockPoint = podaj_wspolrzedne();
        } while (!arr.ifBlockIsPosible(blockPoint, quennMovePoint, player));
        arr.setPoint(blockPoint, Global.block);
        printArray(arr.arr);
        return true;

    }


    private Point podaj_wspolrzedne() {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.print("Podaj wspolrzedne");
            String s = sc.next();
            if (s.length() == 2) {
                if (s.charAt(0) > 64 && s.charAt(0) < 75 && s.charAt(1) > 47 && s.charAt(1) < 57) {
                    int i = s.charAt(0) - 65;
                    int j = s.charAt(1) - 48;
                    return new Point(j, i);
                }
            }
        }
    }

    private void printArray(String[][] arr) {
        System.out.print("  ");
        for (int i = 0; i < 10; i++) {
            int charcode = i + 65;
            System.out.print((char) charcode + " ");
        }
        System.out.println();
        for (int i = 0; i < 10; i++) {
            System.out.print(i + " ");
            for (int j = 0; j < 10; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        launch();
    }

}
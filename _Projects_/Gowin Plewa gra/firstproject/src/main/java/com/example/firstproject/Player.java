package com.example.firstproject;
import java.awt.Point;


public class Player {
    Point queen1;
    Point queen2;
    String symbol;

    Player(int a, int b, int c, int d, String sym){
        queen1=new Point(a,b);
        queen2=new Point(c,d);
        symbol=sym;
    }

    Point[] getQuenns(){
        return new Point[]{queen1,queen2};
    }
    void setQueen(int which,Point p){
        if(which==1){
            queen1=p;
        }
        else{
            queen2=p;
        }
    }
    String getSymbol(){
        return symbol;
    }

    public void changePoint(Point quennPoint, Point quennMovePoint) {
        if(quennPoint.equals(queen1)){
            queen1=quennMovePoint;
        }
        else{
            queen2=quennMovePoint;
        }

    }
}

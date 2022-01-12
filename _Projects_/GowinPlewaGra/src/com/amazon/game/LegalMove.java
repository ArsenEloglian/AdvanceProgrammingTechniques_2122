package com.amazon.game;
import javafx.scene.shape.Circle;

public class LegalMove extends Circle{

    LegalMove(int x, int y) {
        setRadius(10);
        relocate(x*100+40,y*100+40);
    }
}

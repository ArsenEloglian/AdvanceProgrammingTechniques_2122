package com.amazon.game;
import javafx.scene.shape.Circle;

public class LegalMove extends Circle  {

    LegalMove(int x, int y) {
        setRadius(5);
        relocate(x*50+20,y*50+20);
    }
}

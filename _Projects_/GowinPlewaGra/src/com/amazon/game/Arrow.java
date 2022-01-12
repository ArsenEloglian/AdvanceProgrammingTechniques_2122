package com.amazon.game;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class Arrow extends ImageView {

    private Image arrowIMG = new Image(getClass().getResourceAsStream("/res/arrow.png"));
    
    public Arrow(int x, int y) {
        setImage(arrowIMG);
        relocate(x * AmazonApp.TILE_SIZE,y * AmazonApp.TILE_SIZE);
    }
}

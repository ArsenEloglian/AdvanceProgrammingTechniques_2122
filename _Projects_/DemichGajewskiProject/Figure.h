#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include <iostream>

enum class FigureColor {
        brown, white
};

class Figure
{
    FigureColor color;
    sf::Sprite sprite;
    bool selected;
    const int size = 56;
    // ------- Coordinates ------- //
    int x;
    int y;

public:
    Figure() = delete;
    Figure(FigureColor c, const sf::Texture& texture, int valX, int valY) : color(c), x(valX), y(valY)
    {
        sprite.setTexture(texture);
        selected = false;

        if(c == FigureColor::brown)
            sprite.setTextureRect(sf::IntRect(size*3, size*0, size, size));
        else
            sprite.setTextureRect(sf::IntRect(size*3, size*1, size, size));
    }

    int getXCoordinate()
    {
        return x;
    }

    int getYCoordinate()
    {
        return y;
    }

    bool getSelectionInfo()
    {
        return selected;
    }

    void displayFigure(sf::RenderWindow &window)
    {
        sprite.setPosition(size*x+1, size*y+3);
        if(selected) {
            sf::RectangleShape shape(sf::Vector2f(56, 56));
            shape.setFillColor(sf::Color::Blue);
            shape.setPosition(x*56+1,y*56+3);
            window.draw(shape);
        }
        window.draw(sprite);
    }

    void setCoordinates(int valX, int valY)
    {
        x = valX;
        y = valY;
    }

    void setSelection(bool val)
    {
        selected = val;
    }

    FigureColor getColor() {
        return color;
    }
};

#endif // FIGURE_H_INCLUDED

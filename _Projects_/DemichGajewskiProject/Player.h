#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Figure.h"

enum class State {
    select, moveFigure, block, waiting
};

class Player
{
    std::string nickname;
    FigureColor color;
    State state;
    int lifes;

public:
    Player() {
        nickname = "none";
        color = FigureColor::white;
        state = State::select;
        lifes = 4;
    }
    Player(std::string name, FigureColor c) {
        nickname = name;
        color = c;
    }
    ~Player() {}

    std::string getNickname() {
        return nickname;
    }

    FigureColor getColor() {
        return color;
    }

    State getState() {
        return state;
    }
    void setState(State s) {
        state = s;
    }

    int getLifes() {
        return lifes;
    }
    void setLifes(int l) {
        lifes = l;
    }
};

#endif // PLAYER_H_INCLUDED

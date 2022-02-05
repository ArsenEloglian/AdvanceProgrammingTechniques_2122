#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include "Figure.h"
#include "Player.h"
#include <iostream>
#include <utility>

enum class CellType {
    figureBrown, figureWhite, blocked, unlocked, possibleMoves, possibleBlocks, blockedFigureBrown, blockedFigureWhite
};

enum class Turn {
    white, brown
};

class Board {
        sf::Texture tBoard, tFigures;
        const int size = 56;
        CellType board[8][8];
        std::vector<Figure> figures;
        bool whiteTurn;
        bool blockState = false;
        const int brownStartCoordinates[4][2] = { {2,0},{5,0},{0,2},{7,2} };
        const int whiteStartCoordinates[4][2] = { {0,5},{2,7},{5,7},{7,5} };
        int brownLife, whiteLife;

    public:
        int oX = -4, oY = 0, nX = 0, nY = 0, bX = 0, bY = 0;
        bool mouseActive = false;
        Board() {
            whiteTurn=true;
            tBoard.loadFromFile("images/new_board.png");
            tFigures.loadFromFile("images/figures.png");
            brownLife=4;
            whiteLife=4;
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    board[i][j] = CellType::unlocked;
                }
            }

            for(int i = 0; i < 4; i++){
                board[brownStartCoordinates[i][0]][brownStartCoordinates[i][1]] = CellType::figureBrown;
                Figure brown(FigureColor::brown, tFigures, brownStartCoordinates[i][0], brownStartCoordinates[i][1]);
                figures.push_back(brown);

                board[whiteStartCoordinates[i][0]][whiteStartCoordinates[i][1]] = CellType::figureWhite;
                Figure white(FigureColor::white, tFigures, whiteStartCoordinates[i][0], whiteStartCoordinates[i][1]);
                figures.push_back(white);
            }
        }

        void printBoard(sf::RenderWindow &window) {
            sf::Sprite sBoard(tBoard);
            sf::RectangleShape shape(sf::Vector2f(56, 56));
            shape.setFillColor(sf::Color::Red);
            shape.setOutlineColor(sf::Color::Black);
            shape.setOutlineThickness(0.5);
            sf::RectangleShape blockedBrown(sf::Vector2f(56, 56));
            blockedBrown.setFillColor(sf::Color::Black);
            blockedBrown.setOutlineColor(sf::Color::Black);
            blockedBrown.setOutlineThickness(0.5);
            sf::RectangleShape blockedWhite(sf::Vector2f(56, 56));
            blockedWhite.setFillColor(sf::Color::White);
            blockedWhite.setOutlineColor(sf::Color::Black);
            blockedWhite.setOutlineThickness(0.5);
            sf::CircleShape circle;
            circle.setRadius(20);

            window.clear();
            window.draw(sBoard);

            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    if(board[i][j] == CellType::possibleMoves) {
                        circle.setFillColor(sf::Color::Green);
                        circle.setPosition(i*56+9, j*56+11);
                        window.draw(circle);
                    }
                }
            }

            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    if(board[i][j] == CellType::possibleBlocks) {
                        circle.setFillColor(sf::Color::Red);
                        circle.setPosition(i*56+9, j*56+11);
                        window.draw(circle);
                    }
                }
            }

            for(auto fig : figures) {
                fig.displayFigure(window);
            }

            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    if(board[i][j] == CellType::blocked){
                        shape.setPosition(i*56+1,j*56+3);
                        window.draw(shape);
                    }
                }
            }

            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    if(board[i][j] == CellType::blockedFigureBrown){
                        blockedBrown.setPosition(i*56+1,j*56+3);
                        window.draw(blockedBrown);
                    }
                }
            }

            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    if(board[i][j] == CellType::blockedFigureWhite){
                        blockedWhite.setPosition(i*56+1,j*56+3);
                        window.draw(blockedWhite);
                    }
                }
            }
        }

        void updateBoard(Turn turn, int oldX, int oldY, int newX, int newY, int blockX, int blockY) {
            board[oldX][oldY] = CellType::unlocked;
            board[newX][newY] = (turn == Turn::white) ? CellType::figureWhite : CellType::figureBrown;
            board[blockX][blockY] = CellType::blocked;

            for(auto& fig : figures) {
                if(fig.getXCoordinate() == oldX && fig.getYCoordinate() == oldY) {
                    fig.setCoordinates(newX, newY);
                    break;
                }
            }

            whiteTurn = !whiteTurn;

            for(int i = 0; i < 8; i++) {
                for(int j = 0; j  < 8; j++) {
                    if(board[i][j] == CellType::figureBrown || board[i][j] == CellType::figureWhite ||
                        board[i][j] == CellType::blockedFigureBrown || board[i][j] == CellType::blockedFigureWhite) {
                        checkIfBlocked(i, j);
                    }
                }
            }
        }

        void block(sf::RenderWindow &window, Player& player, Turn& t, bool isOver){
            if(isOver){
                if(t == Turn::white) t = Turn::brown;
                else t = Turn::white;
                return;
            }
            if(!mouseActive) return;

            if(!blockState) return;

            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int tempX = pos.x, tempY = pos.y, xCount = 0, yCount = 0;
            while(tempX/56 !=0){
                tempX-=56;
                xCount++;
            }
            while(tempY/56 !=0){
                tempY-=56;
                yCount++;
            }

            if(board[xCount][yCount] == CellType::possibleBlocks){
                board[xCount][yCount] = CellType::blocked;
                clearPossiblePositions(CellType::possibleBlocks);

                bX = xCount;
                bY = yCount;

                for(auto& fig : figures) {
                    if(fig.getSelectionInfo()) {
                        fig.setSelection(false);
                        whiteTurn = !whiteTurn;
                        break;
                    }
                }

                for(int i = 0; i < 8; i++) {
                    for(int j = 0; j  < 8; j++) {
                        if(board[i][j] == CellType::figureBrown || board[i][j] == CellType::figureWhite ||
                           board[i][j] == CellType::blockedFigureBrown || board[i][j] == CellType::blockedFigureWhite) {
                            checkIfBlocked(i, j);
                        }
                    }
                }
                blockState = false;
                player.setState(State::waiting);
                if(t == Turn::white) t = Turn::brown;
                else t = Turn::white;
            }
        }

        void selectFigure(sf::RenderWindow &window, Player& player) {
            if(!mouseActive) return;

            if(blockState) return;

            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int tempX = pos.x, tempY = pos.y, xCount = 0, yCount = 0;
            while(tempX/56 !=0){
                tempX-=56;
                xCount++;
            }
            while(tempY/56 !=0){
                tempY-=56;
                yCount++;
            }
            if((whiteTurn && board[xCount][yCount] == CellType::figureWhite) || (!whiteTurn && board[xCount][yCount] == CellType::figureBrown) ||
               (whiteTurn && board[xCount][yCount] == CellType::blockedFigureWhite) || (!whiteTurn && board[xCount][yCount] == CellType::blockedFigureBrown)) {
                for(auto& fig : figures) {
                    if(fig.getSelectionInfo())
                        fig.setSelection(false);
                }
                for(auto& fig : figures) {
                    if(fig.getXCoordinate() == xCount && fig.getYCoordinate() == yCount) {
                        fig.setSelection(true);
                        break;
                    }
                }
                clearPossiblePositions(CellType::possibleMoves);
                setPossiblePositions(CellType::possibleMoves);
                player.setState(State::moveFigure);
                oX = xCount;
                oY = yCount;
            }
        }

        void moveFigure(sf::RenderWindow &window, Player& player) {
            if(!mouseActive) return;

            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int tempX = pos.x, tempY = pos.y, xCount = 0, yCount = 0;
            while(tempX/56 !=0){
                tempX-=56;
                xCount++;
            }
            while(tempY/56 !=0){
                tempY-=56;
                yCount++;
            }

            if(board[xCount][yCount] == CellType::possibleMoves) {
                for(auto& fig : figures) {
                    if(fig.getSelectionInfo()) {
                        board[fig.getXCoordinate()][fig.getYCoordinate()] = CellType::unlocked;
                        fig.setCoordinates(xCount, yCount);
                        if(whiteTurn){
                            board[xCount][yCount] = CellType::figureWhite;
                        }
                        else{
                            board[xCount][yCount] = CellType::figureBrown;
                        }
                    }
                }
                clearPossiblePositions(CellType::possibleMoves);
                setPossiblePositions(CellType::possibleBlocks);
                player.setState(State::block);
                nX = xCount;
                nY = yCount;
                blockState = true;
                for(int i = 0; i < 8; i++) {
                    for(int j = 0; j  < 8; j++) {
                        if(board[i][j] == CellType::figureBrown || board[i][j] == CellType::figureWhite ||
                           board[i][j] == CellType::blockedFigureBrown || board[i][j] == CellType::blockedFigureWhite) {
                            checkIfBlocked(i, j);
                        }
                    }
                }
            }
        }

        void setPossiblePositions(CellType type) {
            for(auto& fig : figures) {
                if(fig.getSelectionInfo()) {
                    int x = fig.getXCoordinate();
                    int y = fig.getYCoordinate();

                    // Horizontal possible positions --------------------------------
                    for(int i = x - 1;  i >= 0; i--) {
                        if(board[i][y] == CellType::unlocked)
                            board[i][y] = type;
                        else break;
                    }
                    for(int i = x + 1; i < 8; i++) {
                        if(board[i][y] == CellType::unlocked)
                            board[i][y] = type;
                        else break;
                    }

                    // Vertical possible positions ----------------------------------
                    for(int i = y - 1; i >= 0; i--) {
                        if(board[x][i] == CellType::unlocked)
                            board[x][i] = type;
                        else break;
                    }
                    for(int i = y + 1; i < 8; i++) {
                        if(board[x][i] == CellType::unlocked)
                            board[x][i] = type;
                        else break;
                    }

                    // Diagonal possible positions -----------------------------------
                    for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
                        if(board[i][j] == CellType::unlocked)
                            board[i][j] = type;
                        else break;
                    }
                    for(int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++) {
                        if(board[i][j] == CellType::unlocked)
                            board[i][j] = type;
                        else break;
                    }
                    for(int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--) {
                        if(board[i][j] == CellType::unlocked)
                            board[i][j] = type;
                        else break;
                    }
                    for(int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++) {
                        if(board[i][j] == CellType::unlocked)
                            board[i][j] = type;
                        else break;
                    }
                }
            }
        }

        void clearPossiblePositions(CellType type) {
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    if(board[i][j] == type)
                        board[i][j] = CellType::unlocked;
                }
            }
        }

        int checkState(){
            if(brownLife==0){
                return 1;
            }
            if(whiteLife==0){
                return 2;
            }
            if(brownLife == -1 || whiteLife == -1){
                return 3;
            }
            return 0;
        }

        void gameOver(sf::RenderWindow &window, sf::Event &event ,std::string won, bool isOnline) {
            std::string message;
            int size;
            if(brownLife == -1 || whiteLife == -1){
                message = "Opponent disconnected";
                size=30;
            }
            else{
                message = won + " won";
                size=60;
            }
            sf::Font font;
            font.loadFromFile("fonts/SuezOne-Regular.ttf");

            sf::Text gameOver;
            gameOver.setFont(font);
            gameOver.setString("Game over!");
            gameOver.setCharacterSize(80);
            gameOver.setFillColor(sf::Color::Blue);
            gameOver.setStyle(sf::Text::Bold);
            gameOver.setOrigin(gameOver.getLocalBounds().width/2.0f, gameOver.getLocalBounds().height/2.0f);
            gameOver.setPosition(300, 160);

            sf::Text winner;
            winner.setFont(font);
            winner.setString(message);
            winner.setCharacterSize(size);
            winner.setFillColor(sf::Color::Blue);
            winner.setStyle(sf::Text::Bold);
            winner.setOrigin(winner.getLocalBounds().width/2.0f, winner.getLocalBounds().height/2.0f);
            winner.setPosition(300, 240);

            sf::RectangleShape button(sf::Vector2f(200, 60));
            button.setFillColor(sf::Color::Black);
            button.setPosition(200,300);

            sf::Text buttonText;
            buttonText.setFont(font);
            buttonText.setString("New game");
            buttonText.setCharacterSize(30);
            buttonText.setFillColor(sf::Color::Blue);
            buttonText.setStyle(sf::Text::Bold);
            buttonText.setOrigin(buttonText.getLocalBounds().width/2.0f, buttonText.getLocalBounds().height/2.0f);
            buttonText.setPosition(300, 320);

            window.draw(gameOver);
            window.draw(winner);
            if(brownLife != -1 && whiteLife != -1 && isOnline == false){
                window.draw(button);
                window.draw(buttonText);

                sf::Vector2i pos = sf::Mouse::getPosition(window);
                if(pos.x>200 && pos.x<400 && pos.y>300 && pos.y<360 && event.type == sf::Event::MouseButtonPressed){
                    newGame();
                }
            }
        }

	void displayDraw(sf::RenderWindow& window) {
            sf::Font font;
            font.loadFromFile("fonts/SuezOne-Regular.ttf");

            sf::Text gameOver;
            gameOver.setFont(font);
            gameOver.setString("Game over!");
            gameOver.setCharacterSize(80);
            gameOver.setFillColor(sf::Color::Blue);
            gameOver.setStyle(sf::Text::Bold);
            gameOver.setOrigin(gameOver.getLocalBounds().width/2.0f, gameOver.getLocalBounds().height/2.0f);
            gameOver.setPosition(300, 160);
            window.draw(gameOver);

            sf::Text draw;
            draw.setFont(font);
            draw.setString("Draw");
            draw.setCharacterSize(size);
            draw.setFillColor(sf::Color::Blue);
            draw.setStyle(sf::Text::Bold);
            draw.setOrigin(draw.getLocalBounds().width/2.0f, draw.getLocalBounds().height/2.0f);
            draw.setPosition(300, 240);
            window.draw(draw);
        }

        void checkIfBlocked(int x, int y){
            bool tab[8]={false,false,false,false,false,false,false,false};
            int i, j;

            // Checking horizontal blocks --------------------------------
            i = x - 1;
            if((board[i][y] == CellType::unlocked || board[i][y] == CellType::possibleMoves ||
                board[i][y] == CellType::possibleBlocks) && i >= 0)
                tab[0] = true;

            i = x + 1;
            if((board[i][y] == CellType::unlocked || board[i][y] == CellType::possibleMoves ||
                board[i][y] == CellType::possibleBlocks) && i < 8)
                tab[1] = true;

            // Checking vertical blocks ----------------------------------
            i = y - 1;
            if((board[x][i] == CellType::unlocked || board[x][i] == CellType::possibleMoves ||
                board[x][i] == CellType::possibleBlocks) && i >= 0)
                tab[2] = true;

            i = y + 1;
            if((board[x][i] == CellType::unlocked || board[x][i] == CellType::possibleMoves ||
                board[x][i] == CellType::possibleBlocks) && i < 8)
                tab[3] = true;

            // Checking diagonal blocks -----------------------------------
            i = x - 1;
            j = y - 1;
            if((board[i][j] == CellType::unlocked || board[i][j] == CellType::possibleMoves ||
                board[i][j] == CellType::possibleBlocks) && i >= 0 && j >= 0)
                tab[4] = true;

            i = x + 1;
            j = y + 1;
            if((board[i][j] == CellType::unlocked || board[i][j] == CellType::possibleMoves ||
                board[i][j] == CellType::possibleBlocks) && i < 8 && j < 8)
                tab[5] = true;

            i = x + 1;
            j = y - 1;
            if((board[i][j] == CellType::unlocked || board[i][j] == CellType::possibleMoves ||
                board[i][j] == CellType::possibleBlocks) && i < 8 && j >= 0)
                tab[6] = true;

            i = x - 1;
            j = y + 1;
            if((board[i][j] == CellType::unlocked || board[i][j] == CellType::possibleMoves ||
                board[i][j] == CellType::possibleBlocks) && i >= 0 && j < 8)
                tab[7] = true;

            int falseCounter=0;
            for(int i=0; i<8; i++){
                if(tab[i]==false) falseCounter++;
            }
            if(falseCounter==8){
                if(board[x][y] == CellType::figureBrown){
                    std::cout << "brownLife--\n";
                    board[x][y] = CellType::blockedFigureBrown;
                    brownLife--;
                }
                if(board[x][y] == CellType::figureWhite){
                    std::cout << "whiteLife--\n";
                    board[x][y] = CellType::blockedFigureWhite;
                    whiteLife--;
                }
            }
            else{
                if(board[x][y] == CellType::blockedFigureBrown){
                    std::cout << "brownLife++\n";
                    board[x][y] = CellType::figureBrown;
                    brownLife++;
                }
                if(board[x][y] == CellType::blockedFigureWhite){
                    std::cout << "whiteLife++\n";
                    board[x][y] = CellType::figureWhite;
                    whiteLife++;
                }
            }
        }

        void newGame(){
            figures.clear();
            whiteTurn=true;
            brownLife=4;
            whiteLife=4;
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    board[i][j] = CellType::unlocked;
                }
            }

            for(int i = 0; i < 4; i++){
                board[brownStartCoordinates[i][0]][brownStartCoordinates[i][1]] = CellType::figureBrown;
                Figure brown(FigureColor::brown, tFigures, brownStartCoordinates[i][0], brownStartCoordinates[i][1]);
                figures.push_back(brown);

                board[whiteStartCoordinates[i][0]][whiteStartCoordinates[i][1]] = CellType::figureWhite;
                Figure white(FigureColor::white, tFigures, whiteStartCoordinates[i][0], whiteStartCoordinates[i][1]);
                figures.push_back(white);
            }

        }

        void setBrownLife(){
            brownLife = -1;
        }

        int mode(sf::RenderWindow &window, sf::Event &event){
            sf::Font font;
            font.loadFromFile("fonts/SuezOne-Regular.ttf");

            sf::Text title;
            title.setFont(font);
            title.setString("Game of Amazons");
            title.setCharacterSize(50);
            title.setFillColor(sf::Color::Blue);
            title.setStyle(sf::Text::Bold);
            title.setOrigin(title.getLocalBounds().width/2.0f, title.getLocalBounds().height/2.0f);
            title.setPosition(300, 160);

            sf::RectangleShape buttonLocal(sf::Vector2f(200, 60));
            buttonLocal.setFillColor(sf::Color::Black);
            buttonLocal.setPosition(350,300);

            sf::Text buttonLocalText;
            buttonLocalText.setFont(font);
            buttonLocalText.setString("Local");
            buttonLocalText.setCharacterSize(30);
            buttonLocalText.setFillColor(sf::Color::Blue);
            buttonLocalText.setStyle(sf::Text::Bold);
            buttonLocalText.setOrigin(buttonLocalText.getLocalBounds().width/2.0f, buttonLocalText.getLocalBounds().height/2.0f);
            buttonLocalText.setPosition(450, 320);

            sf::RectangleShape buttonOnline(sf::Vector2f(200, 60));
            buttonOnline.setFillColor(sf::Color::Black);
            buttonOnline.setPosition(50,300);

            sf::Text buttonOnlineText;
            buttonOnlineText.setFont(font);
            buttonOnlineText.setString("Online");
            buttonOnlineText.setCharacterSize(30);
            buttonOnlineText.setFillColor(sf::Color::Blue);
            buttonOnlineText.setStyle(sf::Text::Bold);
            buttonOnlineText.setOrigin(buttonOnlineText.getLocalBounds().width/2.0f, buttonOnlineText.getLocalBounds().height/2.0f);
            buttonOnlineText.setPosition(150, 320);

            window.draw(title);
            window.draw(buttonLocal);
            window.draw(buttonLocalText);
            window.draw(buttonOnline);
            window.draw(buttonOnlineText);
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            if(pos.x>50 && pos.x<250 && pos.y>300 && pos.y<360 && event.type == sf::Event::MouseButtonPressed){
                return 1;
            }
            else if(pos.x>350 && pos.x<550 && pos.y>300 && pos.y<360 && event.type == sf::Event::MouseButtonPressed){
                return 2;
            }
            return 0;
        }

	// Funkcja zwraca pare: czy poziomy rzad jest zablokowany i wspolrzedna y blokady
        std::pair<bool, int> rowBlockedHorizontal() {
            bool isRowBlocked = false;
            int y = -1;

            for(int i = 0; i < 8; i++) {
                int blocksCount = 0;
                for(int j = 0; j < 8; j++) {
                    if(board[j][i] == CellType::blocked) blocksCount++;
                }
                if(blocksCount == 8) {
                    isRowBlocked = true;
                    y = i;
                    break;
                }
            }
            return std::make_pair(isRowBlocked, y);
        }

        // Funkcja zwraca pare: czy pionowy rzad jest zablokowany i wspolrzedna x blokady
        std::pair<bool, int> rowBlockedVertical() {
            bool isRowBlocked = false;
            int x = -1;

            for(int i = 0; i < 8; i++) {
                int blocksCount = 0;
                for(int j = 0; j < 8; j++) {
                    if(board[i][j] == CellType::blocked) blocksCount++;
                }
                if(blocksCount == 8) {
                    isRowBlocked = true;
                    x = i;
                    break;
                }
            }
            return std::make_pair(isRowBlocked, x);
        }

        bool arePlayersBlocked() {
            if(!rowBlockedHorizontal().first && !rowBlockedVertical().first) return false;

            if(rowBlockedHorizontal().first)
            {
                int yCoord = rowBlockedHorizontal().second;

                // Wszystkie biale o wspolrzednej y mniejszej niz wspolrzedna blokady
                bool case1 = true;
                for(auto figure : figures) {
                    if(figure.getColor() == FigureColor::white) {
                        if(figure.getYCoordinate() > yCoord) {
                            case1 = false;
                            break;
                        }
                    }
                }

                // Wszystkie brazowe o wspolrzednej y wiekszej niz wpolrzedna blokady
                bool case2 = true;
                for(auto figure : figures) {
                    if(figure.getColor() == FigureColor::brown) {
                        if(figure.getYCoordinate() < yCoord) {
                            case2 = false;
                            break;
                        }
                    }
                }

                if(case1 && case2) return true;


                // Wszystkie biale o wspolrzednej y wiekszej niz wspolrzedna blokady
                bool case3 = true;
                for(auto figure : figures) {
                    if(figure.getColor() == FigureColor::white) {
                        if(figure.getYCoordinate() < yCoord) {
                            case3 = false;
                            break;
                        }
                    }
                }

                // Wszystkie brazowe o wspolrzednej y mniejszej niz wpolrzedna blokady
                bool case4 = true;
                for(auto figure : figures) {
                    if(figure.getColor() == FigureColor::brown) {
                        if(figure.getYCoordinate() > yCoord) {
                            case4 = false;
                            break;
                        }
                    }
                }

                if(case3 && case4) return true;
            }
            else
            {
                int xCoord = rowBlockedVertical().second;

                // Wszystkie biale o wspolrzednej x mniejszej niz wspolrzedna blokady
                bool case1 = true;
                for(auto figure : figures) {
                    if(figure.getColor() == FigureColor::white) {
                        if(figure.getXCoordinate() > xCoord) {
                            case1 = false;
                            break;
                        }
                    }
                }

                // Wszystkie brazowe o wspolrzednej x wiekszej niz wpolrzedna blokady
                bool case2 = true;
                for(auto figure : figures) {
                    if(figure.getColor() == FigureColor::brown) {
                        if(figure.getXCoordinate() < xCoord) {
                            case2 = false;
                            break;
                        }
                    }
                }

                if(case1 && case2) return true;


                // Wszystkie biale o wspolrzednej x wiekszej niz wspolrzedna blokady
                bool case3 = true;
                for(auto figure : figures) {
                    if(figure.getColor() == FigureColor::white) {
                        if(figure.getXCoordinate() < xCoord) {
                            case3 = false;
                            break;
                        }
                    }
                }

                // Wszystkie brazowe o wspolrzednej x mniejszej niz wpolrzedna blokady
                bool case4 = true;
                for(auto figure : figures) {
                    if(figure.getColor() == FigureColor::brown) {
                        if(figure.getXCoordinate() > xCoord) {
                            case4 = false;
                            break;
                        }
                    }
                }

                if(case3 && case4) return true;
            }

            return false;
        }
};

#endif // BOARD_H_INCLUDED

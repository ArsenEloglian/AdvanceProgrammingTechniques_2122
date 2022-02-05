#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Player.h"
#include "Board.h"
#include <SFML/Network.hpp>

const sf::IpAddress ServerIP( "10.0.2.13" );
const unsigned ServerPort = 8888;

class Game
{
    Player whitePlayer{"Player1", FigureColor::white};
    Player brownPlayer{"Player2", FigureColor::brown};
    Board board;
    Turn turn;
    Turn yourTurn;
    bool isBrown;
    sf::TcpSocket sock;

public:
    Game() {
        turn = Turn::white;
    }
    ~Game() {}

    Turn getTurn() {
        return turn;
    }
    void setTurn(Turn t) {
        turn = t;
    }

    Board& getBoard() {
        return board;
    }

    Player& getPlayer() {
        if(turn == Turn::white)
            return whitePlayer;
        return brownPlayer;
    }

    void socketInit(sf::RenderWindow &window){
        if(sock.connect(ServerIP,ServerPort) != sf::TcpSocket::Done){
            std::cout << "Connection error\n";
            window.close();
            return;
        }
        else{
            std::cout << "Connected to server\n";
        }
    }

    void socketSend(int oldX, int oldY, int newX, int newY, int blockX, int blockY){
        sf::Packet packOut;
        packOut << oldX << oldY << newX << newY << blockX << blockY;
        if(sock.send(packOut) == sf::Socket::Status::Done)
            std::cout << "send\n";
    }

    void socketReceive(sf::RenderWindow &window, bool isOnline, bool isOver){
        sf::Packet packIn;
        while(true){
            sf::Packet packIn;
            int oldX, oldY, newX, newY, blockX, blockY;
            if (sock.receive(packIn) == sf::Socket::Done) {
                packIn >> oldX;
                if(oldX == -1){
                    std::string message;
                    packIn >> message;
                    std::cout << message;
                    board.setBrownLife();
                }
                else if(oldX == -2){
                    std::cout << "Color white\n";
                    yourTurn = Turn::white;
                    isBrown=false;
                }
                else if(oldX == -3){
                    std::cout << "Color brown\n";
                    yourTurn = Turn::brown;
                    isBrown=true;
                    drawInterface(window, isOnline, isOver);
                }
                else if(oldX == -4){
                    std::cout << "Test file\n";
                }
                else{
                    packIn >> oldY >> newX >> newY >> blockX >> blockY;
                    std::cout << "pack received: " << oldX << ' ' << oldY << ' ' << newX << ' ' << newY << ' ' << blockX << ' ' << blockY << "\n";
                    board.updateBoard(turn, oldX, oldY, newX, newY, blockX, blockY);
                    turn = yourTurn;
                }
                break;
            }
        }
    }

    void socketDisconnect(){
        sock.disconnect();
    }

    void drawInterface(sf::RenderWindow &window, bool isOnline, bool isOver)
    {
        // ------------------ BOARD -----------------
        board.printBoard(window);

        // ------------------ FONT ------------------
        sf::Font font;
        font.loadFromFile("fonts/IMFellGreatPrimerSC-Regular.ttf");
        sf::Text text;
        text.setFont(font);
        text.setString("Turn");
        text.setCharacterSize(45);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        text.setPosition(470, 5);
        window.draw(text);

        // ------------------ TURN ------------------
        sf::Texture figures;
        figures.loadFromFile("images/figures.png");
        sf::Sprite sprite;
        sprite.setTexture(figures);
        if(turn == Turn::white)
            sprite.setTextureRect(sf::IntRect(56*3, 56*1, 56, 56));
        else
            sprite.setTextureRect(sf::IntRect(56*3, 56*0, 56, 56));
        sprite.setPosition(495, 60);
        window.draw(sprite);
        if(turn != yourTurn && isOver != true && isOnline == true){
            sf::Font font;
            font.loadFromFile("fonts/SuezOne-Regular.ttf");
            sf::Text text;
            text.setFont(font);
            text.setString("Opponent's turn");
            text.setCharacterSize(50);
            text.setFillColor(sf::Color::Blue);
            text.setStyle(sf::Text::Bold);
            text.setOrigin(text.getLocalBounds().width/2.0f, text.getLocalBounds().height/2.0f);
            text.setPosition(300, 200);
            window.draw(text);
        }
	if(board.arePlayersBlocked()) board.displayDraw(window);
    }

    void playerTurn(sf::RenderWindow &window, bool isOnline, bool isOver) {
        if(isOnline){
            if(turn == yourTurn)
            {
                board.mouseActive = true;
                if(isBrown){
                    board.selectFigure(window, brownPlayer);
                    board.moveFigure(window, brownPlayer);
                    board.block(window, brownPlayer, turn, isOver);
                }
                else{
                    board.selectFigure(window, whitePlayer);
                    board.moveFigure(window, whitePlayer);
                    board.block(window, whitePlayer, turn, isOver);
                }
                if(turn != yourTurn){
                    socketSend(board.oX,board.oY, board.nX, board.nY, board.bX, board.bY);
                }
            }
            else
            {
                board.mouseActive = false;
                socketReceive(window, isOnline, isOver);
            }
        }
        else{
            board.mouseActive = true;
            if(turn == Turn::white)
            {
                board.selectFigure(window, whitePlayer);
                board.moveFigure(window, whitePlayer);
                board.block(window, whitePlayer, turn, isOver);
            }
            else
            {
                board.selectFigure(window, brownPlayer);
                board.moveFigure(window, brownPlayer);
                board.block(window, brownPlayer, turn, isOver);
            }
        }
    }
};

#endif // GAME_H_INCLUDED

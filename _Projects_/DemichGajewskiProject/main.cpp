#include "Board.h"
#include "Game.h"

int main()
{
    bool isOnline=false;
    bool start=true;
    bool isOver=false;
    sf::RenderWindow window(sf::VideoMode(600, 455), "Game of the Amazons", sf::Style::Close);
    Game g;
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }
        if(e.type == sf::Event::MouseButtonPressed && e.type != sf::Event::LostFocus && start==false)
            g.playerTurn(window, isOnline, isOver);

        g.drawInterface(window, isOnline, isOver);

        if(start){
            if(g.getBoard().mode(window, e)){
                if(g.getBoard().mode(window,e)==1){
                    isOnline=true;
                    g.socketInit(window);
                    g.socketReceive(window, isOnline, isOver);
                }
                else{
                    isOnline=false;
                }
                start=false;
            }
        }

        if(g.getBoard().checkState()){
            isOver=true;
            g.drawInterface(window, isOnline, isOver);
            if(g.getBoard().checkState()==1) g.getBoard().gameOver(window, e, "White", isOnline);
            else if(g.getBoard().checkState()==2) g.getBoard().gameOver(window, e, "Brown", isOnline);
            else if(g.getBoard().checkState()==3) g.getBoard().gameOver(window, e, "Brown", isOnline);
            if(!isOnline){
                g.setTurn(Turn::white);
                isOver=false;
            }
        }
        window.display();
    }
    g.socketDisconnect();
    return 0;
}

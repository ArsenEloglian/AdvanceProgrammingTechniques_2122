#include <SFML/Network.hpp>
#include <list>
#include <iostream>
#include <windows.h>

const sf::IpAddress ServerIP("10.0.2.13");
const unsigned ServerPort = 8888;
const int clientsNumber = 2;
class Server {
    sf::TcpListener listener;
    std::list<sf::TcpSocket*> clients;
    sf::SocketSelector socketSelector;
    int counter=0;
    sf::TcpSocket::Status socketStatus;
public:
    Server() {
        listener.listen(ServerPort, ServerIP);
        socketSelector.add(listener);
    }
    void run() {
        std::cout << "Start Server:\n";
        sf::Packet packIn;
        sf::Packet packOut;
        int lostCounter=0;
        int color=0;
        for(int i=0; i<clientsNumber; i++){
            sf::TcpSocket* client = new sf::TcpSocket;
            if(listener.accept(*client) == sf::TcpListener::Done) {
                clients.push_back(client);
                socketSelector.add(*client);
                std::cout << "New connection\n";
                if(color%2 == 0){
                    packOut << -2;
                }
                else{
                    packOut << -3;
                }
                sf::TcpSocket& s = *client;
                s.send(packOut);
                packOut.clear();
                color++;
            }
            else {
                std::cout << "Connection lost\n";
                delete client;
                i--;
            }
        }
        while(true) {
            if(clients.size()>1) {
                int counter=0;
                for(auto firstClient = clients.begin(); firstClient != clients.end(); firstClient++, counter++) {
                    auto client = *firstClient;
                    socketStatus = client->receive(packIn);
                    if(socketStatus == sf::TcpSocket::Done) {
                        int a,b,c,d,e,f;
                        packIn >> a >> b >> c >> d >> e >> f;
                        std::cout << counter <<" Received: " << a << ',' << b << ',' << c << ',' << d << ',' << e << ',' << f << '\n';
                        packOut << a << b << c << d << e << f;
                        packIn.clear();
                        if(counter%2 == 0){
                            ++firstClient;
                            sf::TcpSocket& secondClient = **firstClient;
                            secondClient.send(packOut);
                            --firstClient;
                            packOut.clear();
                        }
                        else if(counter%2 != 0){
                            --firstClient;
                            sf::TcpSocket& secondClient = **firstClient;
                            secondClient.send(packOut);
                            ++firstClient;
                            packOut.clear();
                        }
                    }
                    else if(socketStatus == sf::TcpSocket::Disconnected){
                        std::cout << "Connection lost";
                        if(counter%2 == 0){
                            ++firstClient;
                            sf::TcpSocket& secondClient = **firstClient;
                            packOut << -1 << "Opponent disconnected";
                            secondClient.send(packOut);
                            --firstClient;
                            packOut.clear();
                            lostCounter++;
                        }
                        else if(counter%2 != 0){
                            --firstClient;
                            sf::TcpSocket& secondClient = **firstClient;
                            packOut << -1 << "Opponent disconnected";
                            secondClient.send(packOut);
                            ++firstClient;
                            packOut.clear();
                        }
                    }
                }
                if(lostCounter==clientsNumber)
                    break;
            }
        }
    }
};

int main(){
    Server s;
    s.run();
    return 0;
}


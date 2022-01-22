Our project is just a simple game similar to chess called: Game of the Amazons(https://en.wikipedia.org/wiki/Game_of_the Amazons) 
written in C++ with usage of SFML library for graphics and network.

In our game player is able to choose one of two modes: local or online. 
In local mode two players can play against each other on one computer. 
In online mode two players can play against each other on different computers that are connected using bridge connection.

In our project there are two programs: 
*GameOfAmazons that serves as client that allows you to play local mode and online mode if server is launched
*server that connects two clients with each other

In order to play game you will need to download SFML library and connect it to GameOfAmazons in your IDE.
Then you will be able to play local mode.
In order to play online mode besides connecting SFML to server using your IDE you will need three computers that are connected
using bridge connection: one to act as a server and two to act as clients. 
Finally you will need to set your server IP address in server/main.cpp and Game.h
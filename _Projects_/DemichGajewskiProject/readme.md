Description:
Our project is just a simple game similar to chess called: Game of the Amazons(https://en.wikipedia.org/wiki/Game_of_the Amazons) 
written in C++ with usage of SFML library for graphics and network.

In our game player is able to choose one of two modes: local or online. 
In local mode two players can play against each other on one computer. 
In online mode two players can play against each other on different computers that are connected using bridge connection.

In our project there are two programs: 
*GameOfAmazons that serves as client that allows you to play local mode and online mode if server is launched
*server that connects two clients with each other

How to launch:
For local mode:
1 Download latest stable version of SFML library (https://www.sfml-dev.org/download.php) compatible with your IDE (for example GCC 7.3.0 MinGW (SEH) - 64-bit for CodeBlocks).
2 Connect SFML library to GameOfAmazons in your IDE (for CodeBlocks: Build options -> GameOfAmazons -> Search directories -> Compiler/Linker and edit library location in both tabs).
Then you will be able to play local mode.
For online mode:
1 Do all the steps for local mode if you haven't already done so
2 Connect SFML library to server in your IDE (for CodeBlocks: Build options -> server -> Search directories -> Compiler/Linker and edit library location in both tabs).
2 Create three virtual machines with windows OS: one for server and two for clients
3 Set connections to bridged
4 Set virtual machines IPs
5 Put program on virtual machines
6 Set your server IP address in server/main.cpp and Game.h
7 Compile server program
8 Go to server/bin/... , copy and add dll files from SFML library to debug or release folder

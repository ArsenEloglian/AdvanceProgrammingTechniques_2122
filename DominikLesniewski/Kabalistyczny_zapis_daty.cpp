#include <iostream>
//SPOJ ID 2598
using namespace std;

int main() {
    char c;
    int counter = 0;
    while((c = getchar()) != '\n') {
        switch(c) {
            case('a'):
                counter += 1;
                break;
            case('b'):
                counter += 2;
                break;
            case('c'):
                counter += 3;
                break;
            case('d'):
                counter += 4;
                break;
            case('e'):
                counter += 5;
                break;
            case('f'):
                counter += 6;
                break;
            case('g'):
                counter += 7;
                break;
            case('h'):
                counter += 8;
                break;
            case('i'):
                counter += 9;
                break;
            case('k'):
                counter += 10;
                break;
            case('l'):
                counter += 20;
                break;
            case('m'):
                counter += 30;
                break;
            case('n'):
                counter += 40;
                break;
            case('o'):
                counter += 50;
                break;
            case('p'):
                counter += 60;
                break;
            case('q'):
                counter += 70;
                break;
            case('r'):
                counter += 80;
                break;
            case('s'):
                counter += 90;
                break;
            case('t'):
                counter += 100;
                break;
            case('v'):
                counter += 200;
                break;
            case('x'):
                counter += 300;
                break;
            case('y'):
                counter += 400;
                break;
            case('z'):
                counter += 500;
                break;
        }
    }
    cout << counter << endl;
}

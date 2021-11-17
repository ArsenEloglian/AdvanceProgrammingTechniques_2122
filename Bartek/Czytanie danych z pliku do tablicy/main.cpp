#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream wejscie("zadanie.txt");
    ofstream out("wynik.txt");
    char tab[700000] = {};
    int tmp = 0;

     while (!wejscie.eof())
       wejscie >> tab[tmp++];
    wejscie.close();

    cout << endl << "ilosc elementow : " << tmp ;

    return 0;
}

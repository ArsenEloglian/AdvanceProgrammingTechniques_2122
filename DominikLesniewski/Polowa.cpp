#include <iostream>

using namespace std;
//ID 1011 spoj

int main() {
    int amount;

    cin >> amount;
    string *tab = new string[amount];
    for(int i = 0; i < amount; i++) {
        cin >> tab[i];
    }
    for(int i = 0; i < amount; i++) {
        cout << tab[i].substr(0,tab[i].length()/2) << endl;
    }

    delete [] tab;
    return 0;
}

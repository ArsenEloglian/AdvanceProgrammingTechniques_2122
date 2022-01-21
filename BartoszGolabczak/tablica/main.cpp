#include <iostream>
//SPOJ ID 3326
using namespace std;

int main() {
    int n;
    long int x;
    char op;
    cin >> n;
    long int tab[n];
    for(int i = 0; i < n; i++) {
        cin >> tab[i];
    }
    cin >> op >> x;
    for(int i = 0; i < n; i++) {
        if (op == '>') {
            if (tab[i] > x) cout << tab[i] << endl;
        }
        else {
            if (tab[i] < x) cout << tab[i] << endl;
        }
    }
    return 0;
}

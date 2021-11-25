// https://pl.spoj.com/problems/STOS/
#include <iostream>

using namespace std;

int main()
{
    int l, poz = 0;
    int* stos = new int[10];
    char znak;
    while (cin >> znak) {
        if (znak == '+') {
            cin >> l;
            if (poz >= 10) cout << ":(" << endl;
            else {
                stos[poz++] = l;
                cout << ":)" << endl;
            }
        }
        else if (znak == '-') {
            if (poz <= 0) cout << ":(" << endl;
            else cout << stos[--poz] << endl;
        }
    }
}
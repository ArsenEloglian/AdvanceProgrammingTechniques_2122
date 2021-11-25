// https://pl.spoj.com/problems/RNO_DOD/
#include <iostream>

using namespace std;

int main()
{
    int t, n, liczba, suma;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        suma = 0;
        for(int j = 0; j < n; j++) {
            cin >> liczba;
            suma += liczba;
        }
        cout << suma << endl;
    }
}
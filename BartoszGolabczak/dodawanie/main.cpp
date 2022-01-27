#include <iostream>

using namespace std;

int main()
{
    cout << "Podaj ilosc liczb do dodania: ";
    int i, b, c, d, e, wynik;
    b = 0 ;
    cin >> i ;
    for (int a = 1; a <= i ; a++){
        b = b + a;
    }
    cout << "Podaj ilosc liczb do dodania: ";
    cin >> c;
    if (c == 2)
    {
        cout << "Podaj 1-wsza liczbe: " ;
        cin >> d ;
        cout << "Podaj 2-ga liczbe: " ;
        cin >> e ;
wynik = d + e;
    }
    cout <<  b << endl;
    cout << wynik << endl;
    return 0;
}

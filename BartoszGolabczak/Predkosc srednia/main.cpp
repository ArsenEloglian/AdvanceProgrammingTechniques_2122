#include <iostream>

using namespace std;

int main()
{

    int a,b,przebieg;
    cout << "podaj ilosc okrazen: ";
    cin >> przebieg;
    for ( int i = 1; i <= przebieg; i++)
    {
        cout << "Predkosc 1 pociagu: ";
       cin >> a;

    cout << "Predkosc 2 pociagu: ";
        cin >> b;

        cout << "Predkosc srednia wynosi: " << 2*a*b/(a+b) << endl;
    }
    return 0;
}

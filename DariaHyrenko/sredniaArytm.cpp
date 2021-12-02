#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int testy;
    cin>>testy;
    int ilosc;
    int* liczby = new int[100];
    double srednia;
    double odl_min;
    int suma = 0, pozycja;
    while(testy--)
    {
        srednia = 0.0;
        odl_min = 10000000.0;
        cin >> ilosc;
        for(int i=0; i < ilosc; i++)
        {
            cin>>liczby[i];
            suma += liczby[i];
        }
        srednia = static_cast<double>(suma) / static_cast<double>(ilosc);
        for(int i = 0; i < ilosc; i++)
        {
            double odleglosc = abs(srednia - liczby[i]);
            if (odleglosc < odl_min)
            {
                odl_min = odleglosc;
                pozycja = i;
            }
        }
        cout<< liczby[pozycja] << '\n';
    }
    return 0;
}
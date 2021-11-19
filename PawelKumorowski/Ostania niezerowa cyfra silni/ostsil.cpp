#include <iostream>
#include <string>

using namespace std;

int silnia(int n)
{
    int wynik = 1;
    for(int i = 2; i <= n; i++)
    {
        wynik *= i;
    }

    return wynik;
}

int ostatniaNiezerowa(int n)
{
    string liczba = to_string(silnia(n));

    for(int i = liczba.length() - 1; i >= 0; i--)
    {
        if(liczba[i] != '0')
            return liczba[i] - '0';
    }

    return 0;
}

int main()
{
    int ileTestow;
    int *liczby;

    cin >> ileTestow;
    liczby = new int[ileTestow];

    for(int i = 0; i < ileTestow; i++)
    {
        cin >> liczby[i];
        liczby[i] = ostatniaNiezerowa(liczby[i]);
    }

    for(int i = 0; i < ileTestow; i++)
    {
        cout << liczby[i];
        
        if(i < ileTestow - 1)
            cout << endl;
    }

    delete[] liczby;
    return 0;
}
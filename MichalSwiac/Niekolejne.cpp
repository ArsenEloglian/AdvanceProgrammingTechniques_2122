// https://pl.spoj.com/problems/NIEKOLEJ/

#include <iostream>

using namespace std;

int main()
{
    int liczba;
    cin>>liczba;

    if (liczba <= 2)
    {
        if (liczba == 0)
        {
           cout<<"0\n";
        }
        else
        {
            cout<<"NIE\n";
        }
    }

    else if (liczba % 2 != 0 && liczba > 2)
    {
        cout<< liczba-liczba/2 <<" ";
        for (int i=0; i<liczba/2; i++)
        {
            cout<< i <<" "<< liczba - i <<" ";
        }
        cout<< (liczba-liczba/2) - 1<<"\n";
    }

    else
    {
        cout<< liczba-liczba/2<<" ";
        for (int i=0; i<liczba/2; i++)
        {
            cout<< i <<" "<< liczba - i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

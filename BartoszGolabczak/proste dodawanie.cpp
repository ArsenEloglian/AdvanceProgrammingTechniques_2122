#include <iostream>

using namespace std;

int main()
{
    int testy;
    cin>>testy;
    int sumowane;
    int wynik;
    int liczba;
    for (int i=0; i<testy; i++)
       {
           cin>>sumowane;
           wynik=0;
           for(int j=0; j<sumowane; j++)
            {
                cin>>liczba;
                wynik=wynik + liczba;
            }
    cout<<wynik<<endl;
       }

    return 0;
}

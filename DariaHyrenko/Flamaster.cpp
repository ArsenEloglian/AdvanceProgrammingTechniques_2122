#include <iostream>
using namespace std;
int main()
{
    int c, licznik = 1;
    const int ile = 201;
    char tekst[ile];
    cin>>c;
    for(int i = 0; i<c; i++)
    {
        cin>>tekst;
        for(int j = 0; j<ile - 1; j++)
        {
            if(tekst[j] == 0) break;
            if(licznik < 3)
            {
                if(tekst[j] == tekst[j+1]) licznik++;
                else licznik = 1;
                if(licznik < 3) cout<<tekst[j];
            }
            else
            {
                if(tekst[j] == tekst[j+1]) licznik++;
                else
                {
                    cout<<licznik;
                    licznik = 1;
                }
            }
        }
        cout<<"Poszczegolne elementy:" << endl;
    }
}

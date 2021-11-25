#include <iostream>
#include <string>

using namespace std;

int main()
{
    string* tekst;
    string skrocony;
    int zest = 0;

    while(zest > 50 || zest < 1)
    {
        cout << "Podaj ilosc zestawow danych (1-50): ";
        cin >> zest;
    }

    tekst = new string[zest];

    for(int i = 0; i < zest; i++)
    {
        cout << "Wpisz tekst: ";
        cin >> tekst[i];
        tekst[i] += "!";
    }

    for(int j = 0; j < zest; j++)
    {
        skrocony = "";
        int powtorzenia = 0;

        for(int i = 1; i < tekst[j].length(); i++)
        {
            if(tekst[j][i] == tekst[j][i-1])
            {
                powtorzenia++;
            }
            else
            {
                if(powtorzenia < 2)
                {
                    for(int k = 0; k <= powtorzenia; k++)
                        skrocony += tekst[j][i-1];
                }
                else
                {
                    skrocony += tekst[j][i-1] + to_string(powtorzenia + 1);
                }

                powtorzenia = 0;
            }
        }
        cout << skrocony << endl;
    }


    return 0;
}

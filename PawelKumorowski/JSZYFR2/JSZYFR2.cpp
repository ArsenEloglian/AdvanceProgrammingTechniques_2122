#include <iostream>
#include <vector>

using namespace std;
vector<int> pierwsze;

void generujPierwsze(int start, int koniec)
{
    for (int i = start; i <= koniec; i++)   //sprawdzamy kolejne liczby z zakresu czy są pierwszymi
    {
        bool pierwsza = true;
        for (int j = 2; j <= i / 2; j++)    //sprawdzamy dzielniki od 2 do połowy czy dają resztę
        {
            if(i % j == 0)
                pierwsza = false;
        }

        if (pierwsza)
        {
            pierwsze.push_back(i);
        }
    }
}

int main()
{
    vector<vector<int>> ciagi;

    int start = 120;
    int koniec = 150;
    generujPierwsze(start, koniec);

    int iloscCiagow;
    cin >> iloscCiagow;

    for (int i = 0; i < iloscCiagow; i++)
    {
        int dlugoscCiagu;
        cin >> dlugoscCiagu;

        vector<int> ciag;
        for (int j = 0; j < dlugoscCiagu; j++)
        {
            int wyraz;
            cin >> wyraz;
            ciag.push_back(wyraz);
        }
        ciagi.push_back(ciag);
    }

    for (int i = 0; i < ciagi.size(); i++)   //sprawdzamy każdy ciąg
    {
        string haslo = "";
        for (int j = 0; j < pierwsze.size(); j++)   //sprawdzamy każdą liczbę pierwszą dla kolejnych ciągów
        {
            for (int k = 0; k < ciagi[i].size(); k++)   //sprawdzamy czy każdy wyraz ciągu odkoduje liczba pierwsza
            {
                int odkodowana = ciagi[i][k] % pierwsze[j];
                if (odkodowana >= 'A' && odkodowana <= 'Z')
                    haslo += (char)odkodowana;
                else
                {
                    haslo = "";
                    break;
                }
            }
            if (!haslo.empty())
            {
                cout << pierwsze[j] << " " << haslo;
                break;
            }
        }
        if(haslo.empty())
            cout << "NIECZYTELNE";

        if(i < ciagi.size() - 1)
            cout << endl;
    }

    return 0;
}

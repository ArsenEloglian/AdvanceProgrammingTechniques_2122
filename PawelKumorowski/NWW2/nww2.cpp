#include <iostream>

using namespace std;

int nwd(int a, int b)
{
    int pom;

    while (b != 0)
    {
        pom = b;
        b = a % b;
        a = pom;
    }

    return a;
}

int nww2(int a, int b)
{
    return a / nwd(a, b) * b;
}

int nww(int *liczby, int liczbyLen)
{
    int wynik = nww2(liczby[0], liczby[1]);
    for(int i = 2; i < liczbyLen; i++)
    {
        wynik = nww2(wynik, liczby[i]);
    }

    return wynik;
}

int main()
{
    int ileTestow, ileLiczb;
    int *liczby, *wyniki;

    cin >> ileTestow;
    wyniki = new int[ileTestow];

    for (int i = 0; i < ileTestow; i++)
    {
        cin >> ileLiczb;
        liczby = new int[ileLiczb];

        for (int j = 0; j < ileLiczb; j++)
        {
            cin >> liczby[j];
        }
            wyniki[i] = nww(liczby, ileLiczb);

        delete[] liczby;
    }

    for(int i = 0; i < ileTestow; i++)
    {
        cout << wyniki[i];
        if(i < ileTestow - 1)
            cout << endl;
    }

    delete[] wyniki;
    return 0;
}
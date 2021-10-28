//https://pl.spoj.com/problems/NWW/
#include <iostream>
using namespace std;

int nww(int* tab, int m, int y);

int maximum;

int  nww(int* tab, int m, int n) {

    for (int i = 0; i < n; ++i)
        if (m % tab[i] != 0)
            return nww(tab, m + maximum, n);

    return m;
}

int main()
{

    int x, y;
    cin >> x;

    while (x--)
    {
        cin >> y;
        int* tab = new int[y];


        for (int i = 0; i < y; i++)
        {
            cin >> tab[i];
        }
        maximum = tab[0];

        for (int i = 1; i < y; i++)
        {
            if (tab[i] > maximum)
            {
                maximum = tab[i];
            }
        }

        cout << nww(tab, maximum, y) << endl;
        delete[] tab;

    }
    return 0;
}

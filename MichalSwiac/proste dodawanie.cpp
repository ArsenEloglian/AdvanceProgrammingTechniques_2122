#include <iostream>

using namespace std;

int main()
{
    int liczbaTestow, a, suma, b ,c,d ;
    cin >> liczbaTestow ;
    for (a=0; c<liczbaTestow; c++)
    {
        suma = 0;
        b = 0;
        cin>>a;
        for (d=0; d<a; d++)
        {
            cin>>b;
            suma=suma+b;
        }
        cout << suma << endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a ;
    for (e=0; e<a; e++)
    {
        c = 0;
        d = 0;
        cin>>b;
        for (f=0; f<b; f++)
        {
            cin>>d;
            c=c+d;
        }
        cout << c << endl;
    }
    return 0;
}

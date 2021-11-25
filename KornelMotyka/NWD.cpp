#include <iostream>
using namespace std;

int nwd(int a, int b);

int main()
{
    int t;
    cin >> t;

    for(int i = 0;i<t;i++)
    {
        int c,d;
        cin >> c >> d;
        cout << nwd(c,d) << '\n';
    }
}

int nwd(int a, int b)
{
    if(a < b)
        swap(a,b);
    if(b == 0)
        return a;
    return nwd(b, a % b);
}

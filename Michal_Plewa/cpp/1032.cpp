#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int n, x, y;
    for (int i=0; i<t; ++i)
    {
        cin>>n;
        cin>>x;
        cin>>y;
        for (int j=0; j<n; ++j)
        {
            if ((j%x == 0) && (j%y != 0))
            {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

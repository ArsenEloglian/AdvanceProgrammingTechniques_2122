#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int input[101];
    int t, i, q;
    cin>>t;
    while(t--)
    {
        cin>>q;
        for(i=1; i<=q; ++i)
        {
            cin>>input[i];
        }
        for(i=1; i<=q; ++i)
        {
            if(i%2==0)
            {
                cout<<input[i]<<" ";
            }
        }
        for(i=1; i<=q; ++i)
        {
            if(i%2!=0)
            {
                cout<<input[i]<<" ";
            }
        }
        cout<<endl;
    }
}

#include <iostream>


using namespace std;

int vsr(int v1, int v2)
{
    return (2*(v1*v2))/(v1+v2);
}


int main()
{
    int t;

    cin>>t;
    int tab[t];
    for (int i=0;i<t;i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        tab[i]=vsr(v1,v2);
    }
    for ( int i=0;i<t;i++)
    {
        cout<<tab[i]<<endl;
    }
}

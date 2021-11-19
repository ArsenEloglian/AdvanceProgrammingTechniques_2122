#include<iostream>
using namespace std;
int main()
{
    int t,n,*tab;
    cin>>t;
    if(t>100) return 0;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        if(t>100) return 0;
        tab = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>tab[j];
        }
        for(int j=n-1;j>=0;j--)
        {
            cout<<tab[j]<<" ";
        }
    }
    return 0;
}

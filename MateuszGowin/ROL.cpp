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
        if(n>100 || n<1) return 0;
        tab = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>tab[(n-1+j)%n];
        }
        for(int j=0;j<n;j++)
        {
            cout<<tab[j]<<" ";
        }
    }
    return 0;
}

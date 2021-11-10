#include<iostream>
using namespace std;
int NWD(int a,int b)
{
    int pom;
    while(b!=0)
    {
        pom=b;
        b=a%b;
        a=pom;
    }
    return a;
}
int main()
{
    int n,a,b,*tab;
    cin>>n;
    if(n<1 || n>20)
        return 0;
    tab = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cin>>b;
        if(a<10 || b>30)
            return 0;
        tab[i]=a/NWD(a,b)*b;
    }
    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<endl;
    }
    delete[] tab;
    return 0;
}

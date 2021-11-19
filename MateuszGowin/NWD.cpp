#include<iostream>
using namespace std;

int NWD(int a, int b)
{
    while(a!=b)
       if(a>b)
           a-=b;
       else
           b-=a;
    return a;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        cout<< NWD(a,b)<<endl;
    }
    return 0;
}

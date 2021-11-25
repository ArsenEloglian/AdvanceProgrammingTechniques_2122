#include <iostream>

using namespace std;

int x(int s,int licz=0)
{
    if (s == 1)
        return licz;
    if(s % 2 == 0)
        return x(s/2,++licz);
    else
        return x(3*s+1,++licz);
}

int main()
{
    int t,n;
    cin>>t;
    for(int i=0; i<t; i++)
    {
       cin>>n;
       cout<<x(n)<<endl;
    }
  return 0;
}

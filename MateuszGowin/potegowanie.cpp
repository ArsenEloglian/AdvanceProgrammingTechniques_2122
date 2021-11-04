#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int mod(int a,string b)
{
    int mod=0;
    for(int i=0; i<b.size(); i++)
        mod=(mod*10+b[i]-'0')%a;
    return mod;
}
int  ostatniZnak(string a,string b)
{
    int exp = (mod(4,b)==0) ? 4 : mod(4,b);
    int res = pow(a[a.size()-1]-'0',exp);
    return res%10;
}
int main()
{
    int max=1000000000,min=1;
    int a,b,d,*tab;
    cin>>d;
    if(d<1 || d>10)
        return 0;
    tab = new int[d];
    for(int i=0; i<d ;i++)
    {
        cin>>a;
        cin>>b;
        if(a<min || b<min || a>max || b>max)
            return 0;
        tab[i]=ostatniZnak(to_string(a),to_string(b));
    }
    for(int i=0; i<d ;i++)
    {
        cout<<tab[i]<<endl;
    }

    delete[] tab;
    return 0;
}

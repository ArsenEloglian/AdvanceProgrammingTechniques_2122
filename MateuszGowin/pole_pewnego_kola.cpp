#include <iostream>

using namespace std;

int main()
{
    double d,r,s;
    double pi=3.141592654;
    cin>>r>>d;
    s=((r*r)-((d*d)/4))*pi;
    printf("%.2lf",s);
    return 0;
}

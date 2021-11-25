#include <iostream>

using namespace std;

int jednosc(unsigned long long, unsigned long long);

int main()
{
    int n;
    unsigned long long a, b;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> a >> b;
        cout << jednosc(a, b) << endl;
    }

    return 0;
}

int jednosc(unsigned long long a, unsigned long long b)
{
    if(b==0) return 1;
    else if(b==1) return (a%10);
    else if((a%10)==1) return 1;
    else if((a%10)==5) return 5;
    else if((a%10)==6) return 6;
    if( ((a%10)==2) || (a%10)==3 || ((a%10)==7) || ((a%10)==8) ) b=(b%4)+4;
    if( ((a%10)==4) || (a%10)==9 ) b=(b%2)+2;
    a%=10;
    int x=a;

    for(unsigned int i=1; i<b; i++)
    {
        x*=a;
        x%=10;
    }
    return x;
}

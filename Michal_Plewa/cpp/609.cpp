#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double r, d;
    cout.setf(ios::fixed);
    cout.precision(2);
    for(;cin>>r>>d;)
    {
        d=d/2;
        cout<<M_PI*(sqrt((r*r)-(d*d)))*(sqrt((r*r)-(d*d)))<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int counter, a, b;
    cin>>counter;
    for(int i=0;i<=counter;i++)
    {
        cin>>a;
        b=0;
        while(true)
        {
            if(a==1)
            {
                break;
            }
            ++b;
            if(a%2==0)
            {
                a=a/2;
            }
            else
            {
                a=(3*a)+1;
            }
        }
        cout<<b<<endl;
    }
    return 0;
}

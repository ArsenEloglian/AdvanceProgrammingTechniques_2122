#include <iostream>

using namespace std;

int main()
{
   int a,b;
   int partia;

   cin >> partia;
     while(partia--)
    {
        cin>>a>>b;
        while(a != b)
        {
            if (a < b)
            {
                b = b - a;
            }
            else if (b < a)
            {
                a = a - b;
            }
        }
    cout<<a + b<<endl;
    }

   return 0;
}

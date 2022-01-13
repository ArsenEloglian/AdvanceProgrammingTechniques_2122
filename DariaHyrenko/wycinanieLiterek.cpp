#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    char litera;
    while(cin >> litera)
    {
       cin>>a;
       for (int i = 0; i < a.length(); i++)
       {
           if(a[i]!=litera) cout<<a[i];
       }
       cout << endl;
    }
    return 0;
}
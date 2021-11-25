#include <iostream>

using namespace std;

int main()
{
    char znak;
    int a,b;
    while(cin >> znak >> a >> b)
    {
    if(znak=='+')
    {
       cout << a+b;
    }
    else if(znak=='-')
    {
       cout << a-b;
    }
    else if(znak=='*')
    {
       cout << a*b;
    }
    else if(znak=='/')
    {
       cout << a/b;
    }
    else if(znak=='%')
    {
       cout << a%b;
    }
    cout<<endl;
    }
    return 0;
}

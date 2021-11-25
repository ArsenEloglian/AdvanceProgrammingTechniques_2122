#include <iostream>

using namespace std;

int main()
{
    char znak;
    int a,b;
    int tab[10];
    while(cin >> znak >> a >> b)
    {
        if(znak=='z')
            tab[a]=b;
        else if(znak=='+')
            cout<<tab[a]+tab[b];
        else if(znak=='-')
            cout<<tab[a]-tab[b];
        else if(znak=='*')
            cout<<tab[a]*tab[b];
        else if(znak=='/')
            cout<<tab[a]/tab[b];
        else if(znak=='%')
            cout<<tab[a]%tab[b];
        cout<<endl;
    }
    return 0;
}

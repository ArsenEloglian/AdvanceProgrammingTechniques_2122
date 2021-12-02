#include <iostream>

using namespace std;

int main()
{
    char znak;
    int a,b;
    int tab[10];
    while(cin >> znak >> a >> b)
    {
        switch(znak) {
            case 'z':
                tab[a] = b; break;
            case '+':
                cout << tab[a] + tab[b]; break;
            case '-':
                cout << tab[a] - tab[b]; break;
            case '*':
                cout << tab[a] * tab[b]; break;
            case '/':
                cout << tab[a] / tab[b]; break;
            case '%':
                cout << tab[a] % tab[b]; break;
        }
        cout<<endl;
    }
}

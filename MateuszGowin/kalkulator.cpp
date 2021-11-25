#include <iostream>

using namespace std;

int main()
{
    char znak;
    int a,b;
    while(cin >> znak >> a >> b)
    {
        switch(znak) {
            case '+':
                cout << a+b;
                break;
            case '-':
                cout << a-b;
                break;
            case '*':
                cout << a*b;
                break;
            case '/':
                cout << a/b;
                break;
            case '%':
                cout << a%b;
                break;
        }
        cout << endl;
    }
}

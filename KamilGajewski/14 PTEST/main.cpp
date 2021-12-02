#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int a,b;
    cout << "Wejscie:\n";
    bool again;
    do{
        again = false;
        cin >> a;
        if(cin.fail() || a<=0 || a>=200){
            cout << "Bledna wartosc! Sprobuj ponownie.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    do{
        again = false;
        cin >> b;
        if(cin.fail() || b<=0 || b>=200){
            cout << "Bledna wartosc! Sprobuj ponownie.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    cout << "\nWyjscie:\n" << a+b;
    return 0;
}

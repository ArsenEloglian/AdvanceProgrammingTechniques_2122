#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x=0;
    bool again;
    cout << "Podaj liczbe naturalna:\n";
    do{
        again = false;
        cin >> x;
        if(cin.fail() || x<=0){
            cout << "Bledna wartosc! Sprobuj ponownie.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    cout << "\nWyjscie:\n";
    if(x<=2){
        cout << "NIE";
    }
    else{
        for(int i=1; i<=x; i+=2){
            cout << i << ' ';
        }
        for(int i=0; i<=x; i+=2){
            cout << i << ' ';
        }
    }
}

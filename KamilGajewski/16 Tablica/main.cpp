#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x=0;
    bool again;
    cout << "Podaj ilosc liczb w tablicy: ";
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
    int tab[x];
    int y;
    cout << "Wejscie:\n";
    for(int i=0;i<x;i++){
        cout << "Wprowadz liczbe na pozycji " << i << ": ";
        do{
            again = false;
            cin >> y;
            if(cin.fail()){
                cout << "Bledna wartosc! Sprobuj ponownie.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        tab[i]=y;
    }
    cout << "\nWyjscie:\n";
    for(int i=x-1;i>-1;i--){
        cout << tab[i] << ' ';
    }
    return 0;
}

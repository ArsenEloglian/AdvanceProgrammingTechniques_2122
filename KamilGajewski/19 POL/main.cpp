#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x=0;
    bool again;
    cout << "Podaj ilosc ciagow: ";
    do{
        again = false;
        cin >> x;
        if(cin.fail() || x<=0 || x>100){
            cout << "Bledna wartosc! Sprobuj ponownie.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    string tab[x];
    string s;
    cout << "Wejscie:\n";
    for(int i=0;i<x;i++){
        cout << "Podaj ciag " << i+1 << ": ";
        do{
            again=false;
            cin >> s;
            if(s.length()%2!=0){
                cout << "Ciag nie posiada parzystej liczby liter. Sprobuj jeszcze raz:\n";
                again=true;
            }
        }while(again);
        tab[i]=s;
    }
    cout << "Output:\n";
    for(int i=0;i<x;i++){
        cout << tab[i].substr(0,(tab[i].length())/2) << '\n';
    }
    return 0;
}

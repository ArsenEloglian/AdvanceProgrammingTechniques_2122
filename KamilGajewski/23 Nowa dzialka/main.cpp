#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
    int x=0;
    bool again;
    cout << "Podaj ilosc zestawow:\n";
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
    int y=0;
    for(int i=0;i<x;i++){
        cout << "\nPodaj ilosc krokow dla zestawu " << i+1 << ":\n";
        do{
            again = false;
            cin >> y;
            if(cin.fail() || y<=0){
                cout << "Bledna wartosc! Sprobuj ponownie.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        tab[i]=y;
    }
    for(int i=0;i<x;i++){
        cout << "Powierzchnia dla zestawu " << i+1 << ": " << tab[i]*tab[i] << '\n';
    }
}

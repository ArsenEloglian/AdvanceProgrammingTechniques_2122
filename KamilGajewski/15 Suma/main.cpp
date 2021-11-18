#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x;
    bool again;
    cout << "Podaj ilosc liczb: \n";
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
    cout << "Wejscie:\n";
    int y;
    for(int i=0;i<x;i++){
        do{
            again = false;
            cin >> y;
            if(cin.fail() || y>100 || y<-100){
                cout << "Bledna wartosc! Sprobuj ponownie.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        tab[i]=y;
    }
    cout << "Wyjscie:\n";
    int suma=0;
    for(int i=0; i<x; i++){
        suma=suma+tab[i];
        cout << suma << '\n';
    }
    return 0;
}

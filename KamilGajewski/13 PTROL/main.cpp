#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x=0;
    bool again;
    cout << "Podaj ilosc zestawow: ";
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
    int tab[x][100];
    int tabIloscLiczb[x];
    int iloscLiczb;
    for(int i=0;i<x;i++){
        cout << "Zestaw " << i+1 << ":\n";
        cout << "Podaj ilosc liczb: ";
        do{
            again = false;
            cin >> iloscLiczb;
            if(cin.fail() || iloscLiczb<=0 || iloscLiczb>100){
                cout << "Bledna wartosc! Sprobuj ponownie.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        tabIloscLiczb[i]=iloscLiczb;
        int y;
        for(int j=0; j<iloscLiczb; j++){
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
            tab[i][j]=y;
        }
    }
    cout << "\nWyjscie:\n";
    for(int i=0;i<x;i++){
        cout << "Zestaw " << i+1 << ":\n";
        for(int j=1;j<tabIloscLiczb[i];j++){
            cout << tab[i][j] << ' ';
        }
        cout << tab[i][0] << '\n';
    }
    return 0;
}

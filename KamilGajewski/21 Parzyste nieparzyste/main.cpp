#include <iostream>
#include <limits>
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
    int y=0;
    cout << "Podaj ilosc liczb w zestawie:\n";
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
    int tab[x][y];
    for(int i=0; i<x; i++){
        cout << "\nZestaw " << i+1 << ":\n";
        int z=0;
        for(int j=0; j<y; j++){
            cout << "Podaj liczbe " << j+1 << ": ";
            do{
                again = false;
                cin >> z;
                if(cin.fail()){
                    cout << "Bledna wartosc! Sprobuj ponownie.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    again=true;
                }
            }while(again);
            tab[i][j]=z;
        }
        cout << '\n';
    }
    for(int i=0; i<x; i++){
        for(int j=1;j<y;j+=2){
            cout << tab[i][j] << ' ';
        }
        for(int j=0;j<y;j+=2){
            cout << tab[i][j] << ' ';
        }
        cout << '\n';
    }
}

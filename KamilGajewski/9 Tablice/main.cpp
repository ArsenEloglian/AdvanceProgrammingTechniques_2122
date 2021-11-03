#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << "Podaj ilosc tablic: " << endl;
    int x=0;
    bool again=false;
    do{
        again = false;
        cin >> x;
        if(cin.fail() || x<=0){
            cout << "Bledna wartosc! Sprobuj ponownie\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    cout << "Podaj dlugosc tablic:" << endl;
    int y=0;
    do{
        again = false;
        cin >> y;
        if(cin.fail() || y<=0){
            cout << "Bledna wartosc! Sprobuj ponownie\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    int tab[x][y];
    int z=0;
    for(int i=0;i<x;i++){
            cout << "Podaj wartosc dla tablicy " << i+1 << endl;
        for(int j=0;j<y;j++){
            do{
                again = false;
                cin >> z;
                if(cin.fail()){
                    cout << "Bledna wartosc! Sprobuj ponownie\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    again=true;
                }
            }while(again);
            tab[i][j]=z;
        }
    }
    cout << '\n';
    for(int i=0;i<x;i++){
            cout << "Odwrocona tablica " << i+1 << endl;
        for(int j=y-1;j>-1;j--){
            cout << tab[i][j] << '\n';
        }
    }
    return 0;
}

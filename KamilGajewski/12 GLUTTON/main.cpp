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
        if(cin.fail() || x<=0){
            cout << "Bledna wartosc! Sprobuj ponownie.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    int liczbaGosci;
    int liczbaCiastekWpudelku;
    int czasJedzenia;
    int iloscCiastek=0;
    int tabPudelek[x];
    for(int i=0;i<x;i++){
        iloscCiastek=0;
        cout << "Zestaw " << i+1 << ":\n";
        cout << "Podaj liczbe gosci:";
        do{
            again = false;
            cin >> liczbaGosci;
            if(cin.fail() || liczbaGosci<=0){
                cout << "Bledna wartosc! Sprobuj ponownie.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        cout << "Podaj liczbe ciastek w pudelku:";
        do{
            again = false;
            cin >> liczbaCiastekWpudelku;
            if(cin.fail() || liczbaCiastekWpudelku<=0){
                cout << "Bledna wartosc! Sprobuj ponownie.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        for(int j=0; j<liczbaGosci;j++){
            cout << "Podaj czas (w sekundach) jedzenia pojedynczego ciastka dla goscia " << j+1 << ":\n";
            do{
                again = false;
                cin >> czasJedzenia;
                if(cin.fail() || czasJedzenia<=0){
                    cout << "Bledna wartosc! Sprobuj ponownie.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    again=true;
                }
            }while(again);
            iloscCiastek=iloscCiastek+86400/czasJedzenia;
        }
        if(iloscCiastek/liczbaCiastekWpudelku==(double(iloscCiastek)/liczbaCiastekWpudelku)){
            tabPudelek[i]=iloscCiastek/liczbaCiastekWpudelku;
        }
        else{
            tabPudelek[i]=iloscCiastek/liczbaCiastekWpudelku+1;
        }
    }
    for(int i=0;i<x;i++){
        cout << "Liczba pudelek dla zestawu " << i+1 << ": " << tabPudelek[i] << '\n';
    }
    return 0;
}

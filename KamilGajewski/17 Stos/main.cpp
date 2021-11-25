#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x=0;
    bool again;
    cout << "Podaj ilosc operacji: ";
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
    int tab[10];
    int licznik=0;
    int licznikWynik=0;
    char c;
    string tabWynik[x];
    cout << "Wejscie:\n";
    for(int i=0; i<x; i++){
        do{
            again=false;
            cin >> c;
            if(c!='+' && c!='-'){
                cout << "Bledna wartosc! Sprobuj jeszcze raz:\n";
                again=true;
            }
        }while(again);
        if(c=='+'){
            if(licznik==10){
                cout << "Stos jest pelny!\n";
                tabWynik[licznikWynik]=":(";
                licznikWynik++;
            }
            else{
                int temp;
                cout << "Podaj wartosc: ";
                do{
                    again = false;
                    cin >> temp;
                    if(cin.fail()){
                    cout << "Bledna wartosc! Sprobuj ponownie.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    again=true;
                    }
                }while(again);
                tab[licznik]=temp;
                licznik++;
                tabWynik[licznikWynik]=":)";
                licznikWynik++;
            }
        }
        else{
            if(licznik==0){
                cout << "Stos jest pusty!\n";
                tabWynik[licznikWynik]=":(";
                licznikWynik++;
            }
            else{
                cout << "Zdejmuje wartosc\n";
                licznik--;
                int temp = tab[licznik];
                tabWynik[licznikWynik]=to_string(temp);
                licznikWynik++;
            }
        }
    }
    cout << "Wyjscie:\n";
    for(int i=0; i<licznikWynik; i++){
        cout << tabWynik[i] << '\n';
    }
}

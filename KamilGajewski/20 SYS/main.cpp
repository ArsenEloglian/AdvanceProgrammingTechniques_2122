#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
    int x=0;
    bool again;
    cout << "Podaj ilosc liczb:\n";
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
    string tab11[x];
    string tab16[x];
    int y;
    for(int i=0;i<x;i++){
        cout << "Podaj liczbe " << i+1 << ":\n";
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
    //11
    int temp=0;
    int reszta=0;
    int tempTab=0;
    for(int i=0;i<x;i++){
        tempTab=tab[i];
        do{
            for(int j=7;j>-1;j--){
                if(tempTab>=pow(11,j)){
                    temp=tempTab/pow(11,j);
                    int a=tempTab;
                    int b=pow(11,j);
                    reszta=a%b;
                    tempTab=reszta;
                    switch (temp){
                        case 1:
                            tab11[i]+='1';
                            break;
                        case 2:
                            tab11[i]+='2';
                            break;
                        case 3:
                            tab11[i]+='3';
                            break;
                        case 4:
                            tab11[i]+='4';
                            break;
                        case 5:
                            tab11[i]+='5';
                            break;
                        case 6:
                            tab11[i]+='6';
                            break;
                        case 7:
                            tab11[i]+='7';
                            break;
                        case 8:
                            tab11[i]+='8';
                            break;
                        case 9:
                            tab11[i]+='9';
                            break;
                        case 10:
                            tab11[i]+='A';
                            break;
                    }
                }
                else{
                    tab11[i]+='0';
                }
            }
        }while(tempTab!=0);
    }
    //16
    for(int i=0;i<x;i++){
        tempTab=tab[i];
        do{
            for(int j=7;j>-1;j--){
                if(tempTab>=pow(16,j)){
                    temp=tempTab/pow(16,j);
                    int a=tempTab;
                    int b=pow(16,j);
                    reszta=a%b;
                    tempTab=reszta;
                    switch (temp){
                        case 1:
                            tab16[i]+='1';
                            break;
                        case 2:
                            tab16[i]+='2';
                            break;
                        case 3:
                            tab16[i]+='3';
                            break;
                        case 4:
                            tab16[i]+='4';
                            break;
                        case 5:
                            tab16[i]+='5';
                            break;
                        case 6:
                            tab16[i]+='6';
                            break;
                        case 7:
                            tab16[i]+='7';
                            break;
                        case 8:
                            tab16[i]+='8';
                            break;
                        case 9:
                            tab16[i]+='9';
                            break;
                        case 10:
                            tab16[i]+='A';
                            break;
                        case 11:
                            tab16[i]+='B';
                            break;
                        case 12:
                            tab16[i]+='C';
                            break;
                        case 13:
                            tab16[i]+='D';
                            break;
                        case 14:
                            tab16[i]+='E';
                            break;
                        case 15:
                            tab16[i]+='F';
                            break;
                    }
                }
                else{
                    tab16[i]+='0';
                }
            }
        }while(tempTab!=0);
    }
    for(int i=0;i<x;i++){
        cout << "Liczba: " <<tab[i] <<" 11: " << tab11[i] << " 16: " << tab16[i] << '\n';
    }
    return 0;
}

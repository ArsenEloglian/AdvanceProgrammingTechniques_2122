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
    string czyDostanieCukierki[x];
    int y=0,z=0;
    for(int i=0; i<x; i++){
        cout << "\nZestaw " << i+1 << ":\nPodaj ilosc dzieci:\n";
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
        cout << "Podaj ilosc cukierkow:\n";
        do{
            again = false;
            cin >> z;
            if(cin.fail() || z<=0){
                cout << "Bledna wartosc! Sprobuj ponownie.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        if(y>z){
            czyDostanieCukierki[i]="NIE";
        }
        else{
            while(y<=z){
                z-=y;
            }
            if(z>0){
                czyDostanieCukierki[i]="TAK";
            }
            else{
                czyDostanieCukierki[i]="NIE";
            }
        }
    }
    cout << "\nCzy zostana cukierki:\n";
    for(int i=0;i<x; i++){
        cout << czyDostanieCukierki[i] << '\n';
    }
}

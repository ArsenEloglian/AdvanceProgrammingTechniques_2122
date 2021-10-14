#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x=0;
    int gr1, gr2;
    cout << "Podaj ile zestawow danych chcesz wprowadzic: ";
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
    int iloscCukierkow[x];
    for(int i=0;i<x;i++){
        cout << "\nZestaw "<< i+1 << "\nPodaj ilosc dzieci w pierwszej grupie: ";
        do{
            again = false;
            cin >> gr1;
            if(cin.fail() || gr1<=0){
                cout << "Bledna wartosc! Sprobuj ponownie\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        cout << "Podaj ilosc dzieci w drugiej grupie: ";
        do{
            again = false;
            cin >> gr2;
            if(cin.fail() || gr2<=0){
                cout << "Bledna wartosc! Sprobuj ponownie\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        int temp1=gr1;
        int temp2=gr2;
        int temp3;
        while(temp2!=0)
        {
            temp3 = temp2;
            temp2 = temp1%temp2;
            temp1 = temp3;
        }
        iloscCukierkow[i]=gr1/temp1*gr2;
    }
	cout<<"\nIlosc cukierkow jaka bedzie potrzebna:\n";
    for(int i=0;i<x;i++){
        cout << "Zestaw "<< i+1 << ": "<< iloscCukierkow[i] << '\n';
    }

	return 0;
}

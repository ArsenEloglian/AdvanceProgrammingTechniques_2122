#include <iostream>
#include <limits>
using namespace std;

int nwd(int a, int b){
    while(a!=b)
        if(a>b){
            a-=b;
        }
        else{
            b-=a;
        }
    return a;
}

int main()
{
    int x=0;
    int a, b;
    cout << "Podaj ile zestawow liczb chcesz wprowadzic: ";
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
    int NWD[x];
    for(int i=0;i<x;i++){
        cout << "\nZestaw "<< i+1 << "\nPodaj a: ";
        do{
            again = false;
            cin >> a;
            if(cin.fail() || a<=0){
                cout << "Bledna wartosc! Sprobuj ponownie\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        cout << "Podaj b: ";
        do{
            again = false;
            cin >> b;
            if(cin.fail() || b<=0){
                cout << "Bledna wartosc! Sprobuj ponownie\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        NWD[i]=nwd(a,b);
    }
	cout<<"\nNWD:\n";
    for(int i=0;i<x;i++){
        cout << "Zestaw "<< i+1 << ": "<< NWD[i] << '\n';
    }

	return 0;
}

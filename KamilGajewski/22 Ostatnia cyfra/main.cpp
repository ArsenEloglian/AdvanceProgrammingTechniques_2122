#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x=0;
    bool again;
    cout << "Podaj liczbe calkowita:\n";
    do{
        again = false;
        cin >> x;
        if(cin.fail()){
            cout << "Bledna wartosc! Sprobuj ponownie.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    if(x>=0){
        cout << "Ostatnia cyfra podanej liczby to: " << x%10;
    }
    else{
        cout << "Ostatnia cyfra podanej liczby to: " << -1*(x%10);
    }
}

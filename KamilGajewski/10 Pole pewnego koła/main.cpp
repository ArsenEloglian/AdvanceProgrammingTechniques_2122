#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

int main()
{
    double r,d;
    cout << "Podaj r: ";
    bool again=false;
    do{
        again = false;
        cin >> r;
        if(cin.fail() || r<=0){
            cout << "Bledna wartosc! Sprobuj ponownie\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    cout << "Podaj d: ";
    do{
        again = false;
        cin >> d;
        if(cin.fail() || d<=0){
            cout << "Bledna wartosc! Sprobuj ponownie\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    cout << "Pole: " << fixed << setprecision(2) << (pow(r,2)-(pow(d,2)/4))*M_PI << endl;
    return 0;
}

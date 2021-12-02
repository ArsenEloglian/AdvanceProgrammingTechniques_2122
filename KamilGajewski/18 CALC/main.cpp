#include <iostream>
#include <limits>
using namespace std;

int main()
{
    char c;
    cout << "Wybierz operacje: +(dodawanie), -(odejmowanie), *(mnozenie), /(dzielenie), %(reszta z dzielenia)" << endl;
    bool again;
    do{
        again=false;
        cin >> c;
        if(c!='+' && c!='-' && c!='*' && c!='/' && c!='%'){
            cout << "Bledna wartosc! Sprobuj ponownie:\n";
            again=true;
        }
    }while(again);
    int x=0;
    cout << "Podaj pierwsza liczbe:\n";
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
    int y=0;
    cout << "Podaj druga liczbe:\n";
    do{
        again = false;
        cin >> y;
        if(cin.fail()){
            cout << "Bledna wartosc! Sprobuj ponownie.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
        else if(c=='/' && y==0){
            cout << "Nie mozna mnozyc przez 0\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    cout << "Wynik:\n";
    switch(c)
    {
        case '+':
            cout << x+y;
            break;
        case '-':
            cout << x-y;
            break;
        case '*':
            cout << x*y;
            break;
        case '/':
            cout << x/y;
            break;
        case '%':
            cout << x%y;
            break;
    }
    return 0;
}

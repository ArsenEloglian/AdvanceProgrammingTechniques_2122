#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int x=0;
    cout << "Podaj ile chcesz wpisac ciagow: ";
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
    string ciagi[x];
    string ciagiLiczby[x];
    cout << "\nPodaj ciagi znakow:\n";
    for(int i=0;i<x;i++){
        cin >> ciagi[i];
    }
    cout << "\nOto wpisane ciagi:\n";
    for(int i=0;i<x;i++){
        cout << ciagi[i] << '\n';
    }
    for(int j=0;j<x;j++){
        char litera=ciagi[j][0];
        int licznikLiter=1;
        for(int i=1; i<=ciagi[j].size();i++){
            if(litera==ciagi[j][i]){
                licznikLiter++;
            }
            else if(i==ciagi[j].size()){
                ciagiLiczby[j]+=litera;
            }
            else{
                if(licznikLiter>2){
                    ciagiLiczby[j]+=litera;
                    ciagiLiczby[j]+= to_string(licznikLiter);
                }
                else if(licznikLiter==2){
                    ciagiLiczby[j]+=litera;
                    ciagiLiczby[j]+=litera;
                }
                else{
                    ciagiLiczby[j]+=litera;
                }
                litera=ciagi[j][i];
                licznikLiter=1;
            }
        }
    }
    cout << "\nOto zakodowane ciagi:\n";
    for(int i=0;i<x;i++){
        cout << ciagiLiczby[i] << '\n';
    }
    return 0;
}

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << "Podaj liczbe tekstow: ";
    int l;
    bool again=false;
    do{
        again = false;
        cin >> l;
        if(cin.fail() || l<=0){
            cout << "Bledna wartosc! Sprobuj ponownie\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            again=true;
        }
    }while(again);
    string lan1,lan2;
    string end[l];
    for(int i=0; i<l; i++){
        cout << "Tekst " << i+1 << "\nPodaj pierwszy lancuch: ";
        cin >> lan1;
        cout << "Podaj drugi lancuch:";
        cin >> lan2;
        int l2;
        if(lan1.length()<=lan2.length()){
            l2=lan1.length();
        }
        else{
            l2=lan2.length();
        }
        for(int j=0;j<l2;j++){
            end[i]+=lan1[j];
            end[i]+=lan2[j];
        }
    }
    cout << "\nTeksty:\n";
    for(int i=0;i<l;i++){
        cout << i+1 << ' ' << end[i] << '\n';
    }
    return 0;
}

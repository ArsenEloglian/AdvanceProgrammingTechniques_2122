#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
    int q=0;
    bool again = false;
    do{
        cout << "How many numbers do you wanna calculate?\n";

        int x=0;
        do{
            again = false;
            cin >> x;
            if(cin.fail() || x<=0){
                cout << "Wrong value! Try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                again=true;
            }
        }while(again);
        int lastNumbers[x];
        int a,b;
        cout << "\nInput:\n";
        for(int i=0; i<x;i++){
            do{
                again = false;
                cout << '\n' << i+1 << '\n';
                cout << "Base: ";
                cin >> a;
                if(cin.fail() || a<1){
                    cout << "Wrong value! Try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    again=true;
                    continue;
                }
                cout << "Exponent:";
                cin >> b;
                if(cin.fail() || b<1){
                    cout << "Wrong value! Try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    again=true;
                    continue;
                }
                if(pow(a,b)<10){
                    lastNumbers[i]=pow(a,b);
                }
                else{
                    lastNumbers[i]=int(pow(a,b))%10;
                }
            }while(again);
        }
        cout << "\nOutput:\n";
        for(int i=0;i<x;i++){
            cout << lastNumbers[i] << '\n';
        }
        cout << "\nDo you wanna calculate other numbers? 1-Yes, 0-No\n";
        cin >> q;
        cout << '\n';
    }while(q==1);
    cout << "Goodbye";
    return 0;
}

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int q=0;
    bool again = false;
    do{
        cout << "How many numbers do you wanna check?\n";

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
        int ten[x];
        int unity[x];
        int y;
        cout << "\nInput:\n";
        for(int i=0; i<x;i++){
            do{
                again = false;
                cin >> y;
                if(cin.fail()){
                    cout << "Wrong value! Try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    again=true;
                }
                else if(y>20){
                    cout << "Value too high! Try again\n";
                    again=true;
                }
                else if(y<0){
                    cout << "Value too low! Try again\n";
                    again=true;
                }
            }while(again);
            long long z=1;
            for(int j=1;j<=y;j++){
                z=z*j;
            }
            if(z%100<10){
                ten[i]=0;
            }
            else{
                ten[i]=(z%100)/10;
            }
            unity[i]=z%10;
        }
        cout << "\nOutput:\n";
        for(int i=0;i<x;i++){
            cout << ten[i] << " " << unity[i] << '\n';
        }
        cout << "\nDo you wanna check other numbers? 1-Yes, 0-No\n";
        cin >> q;
        cout << '\n';
    }while(q==1);
    cout << "Goodbye";
    return 0;
}

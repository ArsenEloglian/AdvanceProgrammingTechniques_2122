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
        string arr[x];

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
            }while(again);
            if(y<=1){
                arr[i]="NO";
            }
            else
            {
                for(int j=2; j<y;j++){
                    if(y%j==0 && arr[i]==""){
                        arr[i]="NO";
                    }
                }
                if(arr[i]==""){
                    arr[i]="YES";
                }
            }
        }
        cout << "\nOutput:\n";
        for(int i=0;i<x;i++){
            cout << arr[i] << '\n';
        }
        cout << "\nDo you wanna check other numbers? 1-Yes, 0-No\n";
        cin >> q;
        cout << '\n';
    }while(q==1);
    cout << "Goodbye";
    return 0;
}

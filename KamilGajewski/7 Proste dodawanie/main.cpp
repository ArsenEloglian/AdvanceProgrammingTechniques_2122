#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int q=0;
    bool again = false;
    do{
        cout << "How many numbers do you wanna add?\n";

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
        int y;
        int sum=0;
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
            sum=sum+y;
        }
        cout << "\nOutput: " << sum << "\n";
        cout << "\nDo you wanna add other numbers? 1-Yes, 0-No\n";
        cin >> q;
        cout << '\n';
    }while(q==1);
    cout << "Goodbye";
    return 0;
}

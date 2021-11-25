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
        int arr[x];
        int arrDigits[x];
        int y, numberOfDigits=0;
        cout << "\nInput:\n";
        for(int i=0; i<x;i++){
            do{
                again = false;
                cin >> y;
                if(cin.fail() || y>80 || y<1){
                    cout << "Wrong value! Try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    again=true;
                }
            }while(again);
            arr[i]=y;
            do{
                ++numberOfDigits;
                y /= 10;
            }while (y);
            arrDigits[i]=numberOfDigits;
            numberOfDigits=0;
        }
        int numberOfAdditions[x];
        for(int i=0;i<x;i++){
            numberOfAdditions[i]=0;
        }
        int temp;
        cout << '\n';
        for(int i=0; i<x; i++){
            if(arrDigits[i]!=1){
                temp=arr[i];
                for(int j=0; j<arrDigits[i]/2;j++){
                    if((temp/10)!=(temp%10)){
                        cout << "Number isn't palindrome" << '\n';
                    }
                    else{
                        cout << "Number is palindrome" << '\n';
                    }
                }
            }
            else{
                cout << "Number is palindrome" << '\n';
            }
        }
        cout << "\nDo you wanna check other numbers? 1-Yes, 0-No\n";
        cin >> q;
        cout << '\n';
    }while(q==1);
    cout << "Goodbye";
}

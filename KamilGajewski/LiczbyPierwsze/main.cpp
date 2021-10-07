#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "How many numbers do you wanna check?";

    int x;
    cin >> x;
    string tab[x];

    int y;
    cout << "Input:\n";
    for(int i=0; i<x;i++){
            cin >> y;
            //cout << y;

            if(y==1){
                tab[i]="NIE";
            }
            else
            {
                for(int j=2; j<y;j++){
                    if(y%j==0 && tab[i]==""){
                        tab[i]="NIE";
                    }
                }
                if(tab[i]==""){
                    tab[i]="TAK";
                }
            }

    }
    for(int i=0;i<x;i++){
        cout << i << " " << tab[i] << '\n';
    }
    return 0;
}

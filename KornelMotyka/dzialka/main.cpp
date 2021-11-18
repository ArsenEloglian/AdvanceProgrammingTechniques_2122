#include <iostream>

using namespace std;

int main()
{
    int ilosc;
    cin>>ilosc;

    if(ilosc<1 || ilosc>500){
        return 0;
    }

    for(int i=0;i<ilosc;i++){
        int kroki;
        cin>>kroki;
        if(kroki<1 || kroki>1000){
        return 0;
        }
        cout<<kroki*kroki<<endl;
    }
}

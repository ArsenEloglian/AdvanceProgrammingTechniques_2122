#include <iostream>

//PRIME_T - Liczby Pierwsze

using namespace std;

int ileLiczb;
int podanaLiczba;
bool liczbaPierwsza;

int main(){

    cin>> ileLiczb;
    int liczbyDoSprawdzenia[ileLiczb];

    for(int i=0;i<ileLiczb; i++)
        cin>> liczbyDoSprawdzenia[i];
    
    for(int i=0;i<ileLiczb; i++){
        podanaLiczba=liczbyDoSprawdzenia[i];
        liczbaPierwsza = true;

        if((podanaLiczba==1)||(podanaLiczba==0)){
            cout<< "NIE" <<endl;
            liczbaPierwsza = false;
        }

        for(int dzielnik=2 ; dzielnik <= podanaLiczba/2; dzielnik++)
            if(podanaLiczba%dzielnik==0){
                cout<< "NIE" <<endl;
                liczbaPierwsza = false;
                break;
            }
        
        if (liczbaPierwsza==true)
            cout<< "TAK" <<endl;
    }
}

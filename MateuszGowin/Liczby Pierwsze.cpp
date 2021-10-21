#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n>100000)
        return -1;
    int tab[n];
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp<1 || tmp>10000)
            return -1;
        tab[i]=tmp;
    }
    bool CzyPierwsza;
    for(int i=0;i<n;i++){
            CzyPierwsza=true;
            if(tab[i]<2){
                CzyPierwsza=false;
            }else{
                for(int j=2;j<tab[i];j++){
                if(tab[i]%j==0){
                    cout<<" "<<tab[i]<<" "<<j<<endl;
                    CzyPierwsza=false;
                    break;
                }
                else{
                    CzyPierwsza=true;
                }
            }
            }
        if(CzyPierwsza)
            cout<<"TAK"<<endl;
        else
            cout<<"NIE"<<endl;
    }
    return 0;
}

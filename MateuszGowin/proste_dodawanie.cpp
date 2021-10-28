#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    if(t<0 || t>100)
        return 0;
    int n;
    int wyniki[t];
    for(int j=0;j<t;j++){
        cin>>n;
        if(n<0)
            return 0;
        int suma=0;
        int *liczby=new int[n];
        for(int i=0;i<n;i++){
           cin>>liczby[i];
           suma+=liczby[i];
        }
        wyniki[j]=suma;
        delete liczby;
    }
    for(int i=0;i<t;i++)
        cout<<wyniki[i]<<endl;
    return 0;
}

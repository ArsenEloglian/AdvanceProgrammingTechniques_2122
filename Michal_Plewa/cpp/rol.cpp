#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    if(t<1&&t>100)
    {
        return -1;
    }
    int ile;
    for(int i=0;i<t;i++){
        cin>>ile;
        if(ile<=1&&ile>100){
            return -1;
        }
        int tab[ile];
        for(int j=0;j<ile;j++){
            cin>>tab[(ile-1+j)%ile];
        }
        for(int k=0;k<ile;k++){
            cout<<tab[k]<<" ";
        }
        cout<<endl;
    }
}

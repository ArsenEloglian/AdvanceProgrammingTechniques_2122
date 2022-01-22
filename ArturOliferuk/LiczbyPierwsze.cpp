#include <iostream>
#include <ctime>
using namespace std;
 
int main(){
    int q, i;
    cin>>q;
    
 for (int j=0; j<q; ++j)
 {
     cin>>i;
     
     if (i==1) cout<<"NIE"<<endl;
     if (i==2) cout<<"TAK"<<endl;
     int l;
     for(l=2; l<i; ++l)
     {
         if ((i%l) == 0)
         {
             cout<<"NIE"<<endl;
             break;
         }
         if (l == (i-1)) cout<<"TAK"<<endl;
     }
 }
}
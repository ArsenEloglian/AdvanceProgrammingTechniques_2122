#include <iostream>
using namespace std;

int main()
  {
   int count;
   for(cin>>count;count--;)
     {
      char pesel[12],mul[]={1,3,7,9,1,3,7,9,1,3,1};
      cin>>pesel;
      int suma=0;
      for(int i=0;i<11;++i){
        suma+=(pesel[i]-'0')*mul[i];
      }
      cout<<"DN"[suma%10>0]<<endl;
     }
   return 0;
  }

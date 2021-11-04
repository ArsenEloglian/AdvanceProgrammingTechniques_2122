#include <iostream>

using namespace std;
int D,L,C;
int main()
{
    cin>>D;
    for(int i=0; i<D; i++)
    {
        cin>>L>>C;
        if(L==1) cout<<"TAK"<<endl;
        else if (C%(L-1)!=0) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    }
    return 0;
}

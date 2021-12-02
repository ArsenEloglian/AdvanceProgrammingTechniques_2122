#include <iostream>
using namespace std;
int main() {
    int n,suma=0,g,t;
    cin>>t;
    for(int j=0; j<t; j++) {

        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>g;
            suma=suma+g;

        }
        cout<<suma<<"\n";
        suma=0;
    }

}

#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; ++i) {
        int a,b;
        cin>>a;
        cin>>b;
        if(10<=a&&b<=30) {
            int m=a*b;
            while (b!=0) {
                int c = a % b;
                a = b;
                b = c;
            }
            cout<<m/a;
        } else {
            return -1;
        }
        cout<<"\n";
    }
}

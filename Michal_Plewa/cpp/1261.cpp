#include <iostream>
using namespace std;
int main() {
    int t, s;
    char pesel[12];
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>> pesel;
        s = 0;
        s+=(pesel[0] - '0')*1;
        s+=(pesel[1] - '0')*3;
        s+=(pesel[2] - '0')*7;
        s+=(pesel[3] - '0')*9;
        s=s+(pesel[4] - '0')*1;
        s=s+(pesel[5] - '0')*3;
        s=s+(pesel[6] - '0')*7;
        s=s+(pesel[7] - '0')*9;
        s=s+(pesel[8] - '0')*1;
        s=s+(pesel[9] - '0')*3;
        s=s+(pesel[10] - '0')*1;

        if (s>0 && s%10 == 0) {
            cout << "D" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}

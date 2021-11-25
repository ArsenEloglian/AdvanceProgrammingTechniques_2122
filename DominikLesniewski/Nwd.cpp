#include <iostream>
//SPOJ ID 601
using namespace std;

int nwd(int a, int b) {
    int carry;
    do {
        carry = a % b;
        if (carry) {
            a = b;
            b = carry;
        }
    }while(carry != 0);

    return b;
}

int main() {
    int n, a, b;
    int *t;

    cin >> n;
    t = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        t[i] = nwd(a,b);
    }

    for(int i = 0; i < n; i++) {
        cout << t[i] << endl;
    }

    return 0;
}

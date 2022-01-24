#include <iostream>
#include <vector>
#include <numeric>
//SPOJ ID 522
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

int nww(int a, int b) {
    return a*b/nwd(a,b);
}

int main() {
    int n, a, b;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << nww(a,b) << endl;
    }

    return 0;
}

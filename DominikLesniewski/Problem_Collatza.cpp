#include <iostream>
//SPOJ ID 708
using namespace std;

int collatz(int s, int counter = 0) {
    if(s == 1) {
        return counter;
    }
    if(s%2 != 0) {
        return collatz(3*s+1, ++counter);
    }
    return collatz(s/2, ++counter);
}

int main() {
    int t, s;
    cin >> t;
    while(t--) {
        cin >> s;
        cout << collatz(s) << endl;
    }
}

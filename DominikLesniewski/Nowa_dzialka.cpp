#include <iostream>
#include <cmath>
//SPOJ ID 1139
using namespace std;

int main() {
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        cout << pow(x,2) << endl;
    }

    return 0;
}

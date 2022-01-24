#include <iostream>
//SPOJ ID 1016
using namespace std;

int main() {
    int t, v1, v2;
    cin >> t;
    while(t--) {
        cin >> v1 >> v2;
        cout << 2 * v1 * v2 / (v1 + v2) << endl;
    }
}

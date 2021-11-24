#include <iostream>
//SPOJ ID 1844
using namespace std;

int main() {
    int s, n, x;
    while(cin >> s >> n) {
        int counter = 0;
        for(int i = 0; i < n; i++) {
            cin >> x;
            if (x == s) counter++;
        }
        cout << counter << endl;
    }
}

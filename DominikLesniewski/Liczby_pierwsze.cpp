#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for(int i = 2; i <= x / 2; i++) if(x % i == 0)  return false;       
    return true;
}

int main() {
    int n, input;
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }
    for(int i = 0; i < n; i++) {
        if(isPrime(v[i])) {
           cout << "TAK" << endl;
        }
        else {
            cout << "NIE" << endl;
        }
    }
}

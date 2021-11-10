#include <iostream>
#include <vector>
#include <numeric>
//SPOJ ID 549
using namespace std;

int main() {
    int t, n;
    int x;

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        vector<int> v(n);
        for(int j = 0; j < n; j++) {
            cin >> x;
            v.push_back(x);
        }
        cout << accumulate(v.begin(), v.end(), 0) << endl;
    }

    return 0;
}

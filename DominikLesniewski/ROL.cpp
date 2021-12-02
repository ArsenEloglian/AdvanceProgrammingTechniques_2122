#include <iostream>
#include <vector>
#include <algorithm>
//SPOJ id 723
using namespace std;

int main() {
    int t, n, x;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> v;
        while(n--) {
            cin >> x;
            v.push_back(x);
        }
        rotate(v.begin(), v.begin()+1, v.end());

        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}

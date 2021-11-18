#include <iostream>
#include <vector>
#include <algorithm>
//SPOJ id 1262
using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k;
    vector<int> v;
    while(n--) {
        cin >> x;
        v.push_back(x);
    }
    rotate(v.begin(), v.begin()+k, v.end());

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

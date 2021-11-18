#include <iostream>
#include <vector>
//SPOJ ID 606
using namespace std;

int main() {
    int t, n;
    vector<vector<int>> v;

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        vector<int> temp(n);
        for(int j = 0; j < n; j++) {
            cin >> temp[j];
        }
        v.push_back(temp);
    }

    for(int i = 0; i < t; i++) {
        for(int j = v[i].size()-1; j >= 0 ; j--) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

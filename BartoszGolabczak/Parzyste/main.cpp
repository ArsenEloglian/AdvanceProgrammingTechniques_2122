#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<vector<int> > v;
    int t, n, input;

    cin >> t;
    for(int i = 0; i < t; i++) {
        vector<int> temp;
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> input;
            temp.push_back(input);
        }
        v.push_back(temp);
    }

    for(int i = 0; i < v.size(); i++) {
        for(int j = 1; j < v[i].size(); j+=2) cout << v[i][j] << " ";

        for(int j = 0; j < v[i].size(); j+=2) cout << v[i][j] << " ";

        cout << endl;

    }
}

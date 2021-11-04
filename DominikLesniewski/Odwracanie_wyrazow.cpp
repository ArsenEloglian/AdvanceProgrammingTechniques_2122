#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//SPOJ id 1910
int main() {
    vector<string> v;
    string input;
    while(cin >> input) {
        v.push_back(input);
    }
    for(int i = 0; i < v.size(); i++) {
        reverse(v[i].begin(), v[i].end());
        cout << v[i] << endl;
    }
    return 0;
}

// https://pl.spoj.com/problems/PP0504B/
#include <iostream>

using namespace std;

// w c++ 'char*' i 'string' jest to samo

string string_merge(string a, string b) {
    string result;
    for(int j = 0, k = 0; k < min(a.length(), b.length()); k++) {
        result += a.at(k);
        j++;
        result += b.at(k);
        j++;
    }
    return result;
}

int main()
{
    string a, b;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << string_merge(a, b) << endl;
    }
}
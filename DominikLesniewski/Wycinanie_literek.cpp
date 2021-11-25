#include <iostream>
#include <string>
//SPOJ ID 2181
using namespace std;

int main() {
    char c;
    string line;
    while(cin >> c >> line) {
        for(int i = 0; i < line.length(); i++) {
            if (line[i] != c) cout << line[i];
        }
        cout << endl;
    }
}

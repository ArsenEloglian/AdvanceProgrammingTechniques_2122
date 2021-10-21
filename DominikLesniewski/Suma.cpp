#include <iostream>
#include <vector>

using namespace std;
//ID 968 spoj

int main() {
    vector<int> numbers;
    int x;

    string line;
    while(true) {
        getline(cin, line);
        if (line.empty()) break;
        x = stoi(line);
        if (numbers.empty()) numbers.push_back(x);
        else numbers.push_back(numbers.back() + x);

    }

    for(int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }

    return 0;
}

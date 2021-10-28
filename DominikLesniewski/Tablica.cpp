#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int input;
    vector<int> numbers;

    while(true) {
        cin >> input;
        numbers.push_back(input);
        if(cin.peek() == '\n') break;
    }

    for (int i = numbers.size()-1; i >= 0 ; i--) {
        cout << numbers[i] << " ";
    }

    return 0;
}


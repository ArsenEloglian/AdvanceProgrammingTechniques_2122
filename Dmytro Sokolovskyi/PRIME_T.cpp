// https://pl.spoj.com/problems/PRIME_T/
#include <iostream>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;

    for (int i = 2; i < number; i++) {
        if (number % i == 0) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    if (n > 100000 || n < 1) return -1;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > 10000 || arr[i] < 1) return -1;
    }

    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
}
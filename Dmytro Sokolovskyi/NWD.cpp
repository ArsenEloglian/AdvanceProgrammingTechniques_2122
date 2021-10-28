// https://pl.spoj.com/problems/PP0501A/
#include <iostream>

using namespace std;

int nwd(int a, int b) {
    if (a < b) return nwd(b, a);
    else {
        int mod = a % b;
        if (mod == 0) return b;
        else return nwd(b, mod);
    }

}

int main()
{
    int n1, n2, numbersCount;
    cin >> numbersCount;
    int* resultTab = new int[numbersCount];
    for (int i = 0; i < numbersCount; i++) {
        cin >> n1;
        cin >> n2;
        resultTab[i] = nwd(n1, n2);
    }

    for (int i = 0; i < numbersCount; i++) {
        cout << resultTab[i] << endl;
    }
}
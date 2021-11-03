//https://pl.spoj.com/problems/TROJPASC/
#include <iostream>
#include <vector>
using namespace std;

void printPascal(int n)
{
    int C = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << C << " ";
        C = C * (n - i) / i;
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;

    vector<int> tab;
    while (t--) {
        int n;
        cin >> n;
        tab.push_back(n);
    }

    for (auto& numb : tab) {
        printPascal(numb + 1);
    }

    return 0;
}

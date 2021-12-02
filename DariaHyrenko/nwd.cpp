#include <iostream>
using namespace std;

int nwd(int a, int b) {
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int test, a, b;
    cin >> test;
    for (int i = 0; i < test ;i ++) {
        cin >> a >> b;
        cout<<nwd(a, b)<<endl;
    }
}
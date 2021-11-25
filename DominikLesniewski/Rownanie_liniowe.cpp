#include <iostream>
#include <iomanip>
//SPOJ ID 1228
using namespace std;

void calculate(double a, double b) {
    if (a == 0 && b == 0) {
        cout << "NWR";
    }
    else if (a == 0 && b != 0) {
        cout << "BR";
    }
    else {
        cout.setf(ios::fixed);
        cout << setprecision(2) << -b/a << endl;
    }
}

int main() {
    double a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;
    calculate(a, b - c);
    return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double promien, d, Pole;

int main()
{
    cin >>promien;
    cin>>d;
    printf("%.2f",(pow(promien,2)-pow(d,2)/4.0)*M_PI);
    return 0;
}

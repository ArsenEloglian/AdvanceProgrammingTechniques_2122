//https://pl.spoj.com/problems/JROWLIN/
#include <iostream>
#include <iomanip>

int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;

    if((c - b) == 0 && a == 0)
        std::cout << "NWR";

    else if ((c-b) != 0 && a == 0)
        std::cout << "BR";

    else
    {
        double result = (c - b)/a;
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout<<result;
    }

    return 0;
}

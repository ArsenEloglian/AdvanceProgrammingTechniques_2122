//https://pl.spoj.com/problems/NIEKOLEJ/
#include <iostream>

int main()
{
    int number;
    std::cin >> number;

    if (number <= 2)
    {
        if (number == 0)
            std::cout << "0\n";
        else
            std::cout << "NIE\n";
    }

    else if (number % 2 != 0 && number > 2)
    {
        std::cout << number - number/2 << ' ';

        for (int i = 0; i < number/2; i++)
            std::cout << i << ' ' << number - i << ' ';

        std::cout << (number - number/2) - 1 << '\n';
    }

    else
    {
        std::cout << number - number/2 << ' ';

        for (int i = 0; i < number/2; i++)
            std::cout << i << ' ' << number - i << ' ';

        std::cout << '\n';
    }
    return 0;
}

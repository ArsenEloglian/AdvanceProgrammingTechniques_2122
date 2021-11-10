//https://pl.spoj.com/problems/PP0602A/
#include <iostream>

int main()
{
    int tests;
    std::cin >> tests;

    while(tests--)
    {
        int counter;
        std::cin >> counter;
        int numbers[counter];

        for(int i = 0; i < counter; i++)
            std::cin >> numbers[i];

        for(int i = 1; i < counter; i = i+2)
            std::cout << numbers[i] << ' ';

        for(int j = 0; j < counter; j = j+2)
            std::cout << numbers[j] << ' ';

        std::cout << '\n';
    }
    return 0;
}

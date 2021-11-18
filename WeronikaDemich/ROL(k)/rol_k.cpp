//https://pl.spoj.com/problems/PP0602D/
#include <iostream>

int main()
{
    int counter, shift;
    std::cin >> counter >> shift;
    int tab[counter];

    for(int i = 0; i < counter; i++) {
        std::cin >> tab[i];
    }
    for (int i = shift; i < counter; i++)
    {
        std::cout << tab[i]<< ' ';
    }
    for (int i = 0; i < shift; i++)
    {
        std::cout << tab[i] << ' ';
    }
}

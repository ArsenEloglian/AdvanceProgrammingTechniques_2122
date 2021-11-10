//https://pl.spoj.com/problems/PP0601B/
#include <iostream>

int main()
{
    int tests;
    std::cin >> tests;
    int maxNumber;
    int x,y;

    while(tests--) {
        std::cin >> maxNumber >> x >> y;
        for(int i = 0; i < maxNumber; i++) {
            if((i%x == 0) && (i%y != 0))
            {
                std::cout << i << ' ';
            }
        }
        std::cout << '\n';
    }

    return 0;
}

//https://pl.spoj.com/problems/FLAMASTE/
#include <iostream>
#include <string>

int main()
{
    int tests;
    std::cin >> tests;

    while(tests--)
    {
        std::string text;
        std::cin >> text;
        int counter = 1;

        for (int i = 1; i <= text.size(); i++)
        {
            if(text[i] != text[i-1])
            {
                if(counter > 2)
                    std::cout << text[i-1] << counter;
                else if (counter == 2)
                    std::cout << text[i-1] << text[i-1];
                else
                    std::cout << text[i-1];
                counter = 1;
            }
            else
                counter++;
        }
        std::cout<<'\n';
    }

    return 0;
}

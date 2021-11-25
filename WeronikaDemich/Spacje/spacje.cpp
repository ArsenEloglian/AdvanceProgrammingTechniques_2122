//https://pl.spoj.com/problems/JSPACE/
#include <iostream>
#include <cctype>
#include <string>

int main()
{
    std::string line;

    while(getline(std::cin, line))
    {
       for(unsigned int i = 0; i < line.size(); i++) {
           if(isspace(line[i]))
           {
               line[i]=0;
               line[i+1]=toupper(line[i+1]);
           }
        }
        for(unsigned int i = 0; i < line.size(); i++) {
            if(line[i] != 0)
                std::cout << line[i];
        }
        std::cout << '\n';
    }

    return 0;
}

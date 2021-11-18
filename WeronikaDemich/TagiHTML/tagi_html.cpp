//http://pl.spoj.com/problems/JHTMLLET/
#include <iostream>
#include <string>

int main()
{
    std::string line;
    while(getline(std::cin, line))
    {
        for(int i = 0; i < line.size(); i++) {
            if(line[i] == '<')
            {
                while(line[i] != '>')
                {
                    i++;
                    line[i] = toupper(line[i]);
                }
            }
        }
        std::cout << line << '\n';
    }

    return 0;
}

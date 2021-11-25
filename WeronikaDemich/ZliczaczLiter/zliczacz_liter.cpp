//https://pl.spoj.com/problems/JZLICZ/
#include <iostream>
#include <algorithm>
#include <cstring>

int chars[256];

void counting(std::string text)
{
    for(int i = 0; i < text.size(); i++) {
        if(text[i] != ' ')
            chars[int(text[i])]++;
    }
}

int main()
{
    int lines;
    std::cin >> lines;
    std::cin.ignore();

    while(lines--) {
        std::string text;
        getline(std::cin, text);
        counting(text);
    }

    for(int i = 97; i <= 122; i++) {
        if(chars[i] != 0)
            std::cout << char(i) << ' ' << chars[i] << '\n';
    }

    for(int i = 65; i <= 90; i++) {
        if(chars[i] != 0)
            std::cout << char(i) << ' ' << chars[i] << '\n';
    }

    return 0;
}

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

void sort(std::map<std::string, int>& M)
{
    std::multimap<int, std::string, std::greater<int>> MM;

    for (auto& it : M) {
        MM.insert({ it.second, it.first });
    }

    for (auto& elem : MM) {
        std::cout << elem.second << ' ' << elem.first << '\n';
    }
}

int main()
{
    std::map<std::string, int> namesMap;

    for (std::string line; std::getline(std::cin, line);) {
        std::string name = line.substr(line.find_last_of(" ") + 1);
        std::transform(name.begin(), name.end(), name.begin(), ::toupper);

        if (namesMap.count(name) > 0) {
            namesMap[name] = namesMap[name] + 1;
        }

        else
            namesMap.insert({ name, 1 });
    }

    sort(namesMap);

    return 0;
}

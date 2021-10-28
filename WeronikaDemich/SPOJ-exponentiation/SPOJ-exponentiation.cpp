//https://pl.spoj.com/problems/POTEGA/
#include <iostream>
#include <string>
#include <deque>
#include <sstream>

void print_result(std::deque<int> &deq) {
    for (auto& elem : deq) {
        std::cout << elem;
    }
}

int main()
{
    std::string str_exponent;
    std::string str_power;

    std::cout << "Enter numbers:" << std::endl;
    std::cin >> str_exponent;
    std::cin >> str_power;

    int power = std::stoi(str_power);
    int exponent = std::stoi(str_exponent);

    std::deque<int> number;

    for (int i = 0; i < power; i++) {

        if (number.empty()) { 
            for (int i = 0; i < str_exponent.size(); i++) {
                number.push_back(str_exponent[i] - '0');
            }
        }

        else {
            int to_add = 0;

            for (int i = number.size() - 1; i >= 0; i--) {
                int value = number[i] * exponent + to_add;

                number[i] = value % 10;

                to_add = value / 10;
            }

            if (to_add > 0)
                number.push_front(to_add);
        }
    }

    print_result(number);

    return 0;
}

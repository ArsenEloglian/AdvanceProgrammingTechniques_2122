//https://pl.spoj.com/problems/CALC/
#include <iostream>

int main()
{
    char operation;
    int result, a, b;

    while(std::cin >> operation >> a >> b) {
        switch(operation)
        {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case'/':
            result = a / b;
            break;
        case '%':
            result = a % b;
            break;
        }
        std::cout << result << std::endl;
    }

    return 0;
}

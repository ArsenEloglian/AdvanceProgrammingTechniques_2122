//https://pl.spoj.com/problems/JPESEL/
#include <iostream>
#include <string>

int main()
{
    int pesel[11];
    std::string strPesel;
    int tests;
    std::cin >> tests;

    while(tests--)
    {
        std::cin >> strPesel;
        for(int i = 0; i < strPesel.size(); i++) {
            pesel[i]=strPesel[i];
        }

        int suma = pesel[0] * 1 + pesel[1] * 3 + pesel[2] * 7 + pesel[3] * 9 + pesel[4] * 1 + pesel[5] * 3 +
                   pesel[6] * 7 + pesel[7] * 9 + pesel[8] * 1 + pesel[9] * 3 + pesel[10] * 1;

        if(suma > 0) {
            if(suma % 10 == 0)
                std::cout << "D\n";
            else
                std::cout << "N\n";
        }
        else
            std::cout << "N\n";
    }

    return 0;
}

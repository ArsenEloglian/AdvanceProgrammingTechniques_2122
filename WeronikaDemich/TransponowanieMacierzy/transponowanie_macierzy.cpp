//https://pl.spoj.com/problems/TRN/
#include <iostream>

int main()
{
    int rows, columns;
    std::cin >> rows >> columns;

    int matrix[rows][columns];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            std::cin >> matrix[i][j];
        }
    }

    for(int j = 0; j < columns; j++) {
        for(int i = 0; i < rows; i++) {
            std::cout << matrix[i][j];
            std::cout << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}

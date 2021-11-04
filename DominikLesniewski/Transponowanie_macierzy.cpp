#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int row, col;
    int **tab;

    scanf("%d %d", &row, &col);
    tab = new int*[row];
    for(int i = 0; i < row; i++) {
        tab[i] = new int[col];
    }

    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d",&tab[i][j]);
        }
    }

    for(int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ",tab[j][i]);
        }
        printf("\n");
    }

    for(int i = 0; i < row; i++) {
        delete tab[i];
    }
    delete tab;

    return 0;
}

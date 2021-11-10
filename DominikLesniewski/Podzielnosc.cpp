#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
//SPOJ id 1032
int main() {
    int c, n, x, y;
    vector< vector<int> > v;

    scanf("%d", &c);
    for(int i = 0; i < c; i++) {
        vector<int> temp;
        scanf("%d %d %d", &n, &x, &y);
        temp.push_back(n);
        temp.push_back(x);
        temp.push_back(y);
        v.push_back(temp);
    }

    for(int i = 0; i < c; i++) {
        for(int j = 1; j < v[i][0]; j++) {
            if (j % v[i][1] == 0 && j % v[i][2] != 0) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}

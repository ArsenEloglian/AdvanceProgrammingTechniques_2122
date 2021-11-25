#include <iostream>
#include <cstring>
#define T_SIZE 1001
//SPOJ id 617
using namespace std;

char* string_merge(char *a, char *b) {
    char *result = new char[T_SIZE*2];
    int i = 0;
    for(int j = 0; j < T_SIZE; j++) {
        if(a[j] == '\0' || b[j] == '\0') {
                break;
        }
        result[i] = a[j];
        i++;
        result[i] = b[j];
        i++;
    }
    result[i] = '\0';
    return result;
}

int main() {
    int t, n;
    char S1[T_SIZE], S2[T_SIZE], *S;
    cin >> t; /* wczytaj liczbê testów */
    cin.getline(S1, T_SIZE);
    while(t--) {
            cin.getline(S1, T_SIZE, ' ');
            cin.getline(S2, T_SIZE);
            S = string_merge(S1, S2);
            cout << S << endl;
            delete[] S;
    }
    return 0;
}

#include <iostream>
#include <string>
//SPOJ ID 2016
using namespace std;

int main() {
    wchar_t c;
    int ascii[256] = {0};

    while((c = getchar()) != EOF) {
        ascii[c]++;
    }
    for(int i = 0; i < 256; i++) {
        if(ascii[i]) cout << i << " " << ascii[i] << endl;
    }
}

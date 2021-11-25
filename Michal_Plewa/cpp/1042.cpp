#include <iostream>

using namespace std;

int main() {
    int m, n;
    int tab [200][200];

    cin>>m;
    cin>>n;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>tab[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<tab[j][i]<<" ";
        }
        cout<<endl;
    }
}


#include iostream
#include vector
using namespace std;

void suma(vector int tab, int k, int s) {
    if(s == 0) {
        for(int i = 0; i  tab.size(); i++) {
            cout  tab[i]   ;
        }
        cout<<endl;
        return;
    }
    for(int i = k; s - i = 0; i++) {
        tab.push_back(i);
        suma(tab, i, s - i);
        tab.pop_back();
    }
}

int main() {
    vector int tab;
    int t, n;

    cin  t;
    while(t--) {
        cin  n;
        suma(tab, 1, n);
    }
}
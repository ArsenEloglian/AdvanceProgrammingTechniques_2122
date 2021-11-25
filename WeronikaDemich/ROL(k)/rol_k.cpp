//https://pl.spoj.com/problems/PP0602D/
#include <iostream>
using namespace std;
int main()
{
    int counter, shift;
    cin >> counter >> shift;
    int tab[counter];
    for(int i = 0; i < counter; i++) {
        cin >> tab[i]; }
    for (int i = shift; i < counter; i++) {
        cout << tab[i]<< ' '; }
    for (int i = 0; i < shift; i++) {
        cout << tab[i] << ' '; }
}

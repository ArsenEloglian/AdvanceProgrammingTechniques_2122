#include <iostream>

using namespace std;

int silnia (int n)
{
    if (n == 0) return 1;
    else return n*silnia(n-1);
}
int t,f;
int main()
{
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin >>f;
        if(f<10)
        {
            cout<<silnia(f)%100/10<<" "<<silnia(f)%10<<endl;
        }
        else cout << "0 0" << endl;
    }
}

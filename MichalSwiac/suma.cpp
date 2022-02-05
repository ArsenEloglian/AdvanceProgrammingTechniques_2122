#include <iostream>

using namespace std;
int liczba;
int suma;

int main()
{
    for(int i=0; i<10; i++)
    {
        cin>>liczba;
        suma+=liczba;
        cout<<suma<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Input:";
    do {
    cin >> x;

   if (x!=42 )
   {
       cout << "Life is good\n";
   }
   else
    cout << "Life doesnt exists";
    } while ( x!= 42);
}

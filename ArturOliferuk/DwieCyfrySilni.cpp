#include <iostream>
#include <ctime>
using namespace std;

int factorial(int i)
{
  if (i==0) return 1;
  else return i*factorial(i-1);
}
 
int main()
{
	int q,n;
    	cin>>q;
    	int fakt=1;
	for (int j=0; j<q; ++j)
	{
		cin>>n;
		if(n>9)
		{
			cout<<0<<" "<<0<<endl;
		}
		else
		{
    			fakt=factorial(n);
			cout<<(fakt%100)/10<<" "<<fakt%10<<endl;
			fakt=1;
		}
	}
}

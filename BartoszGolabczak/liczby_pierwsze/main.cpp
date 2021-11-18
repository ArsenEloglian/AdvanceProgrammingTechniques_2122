#include<iostream>
using namespace std;

bool czy_pierwsza(int n)
{
	if(n<2)
		return false; //gdy liczba jest mniejsza ni¿ 2 to nie jest pierwsz¹

	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
	return true;
}

int main()
{
	int n;

	cout<<"Podaj liczbê: ";
	cin>>n;

	if(czy_pierwsza(n)) //lub czy_pierwsza(n)==1
		cout<<"Liczba "<<n<<" jest pierwsza"<<endl;
	else
		cout<<"Liczba "<<n<<" nie jest pierwsza"<<endl;

	return 0;
}

// https://pl.spoj.com/problems/JPESEL/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t, suma;
	string pesel;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> pesel;
		suma = 0;
		suma += pesel[0];
		suma += pesel[1] * 3;
		suma += pesel[2] * 7;
		suma += pesel[3] * 9;
		suma += pesel[4];
		suma += pesel[5] * 3;
		suma += pesel[6] * 7;
		suma += pesel[7] * 9;
		suma += pesel[8];
		suma += pesel[9] * 3;
		suma += pesel[10];
		if (suma % 10)
			cout << "N" << endl;
		else
			cout << "D" << endl;
	}

	return 0;
}

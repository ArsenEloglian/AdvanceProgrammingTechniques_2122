#include <iostream>
#include <string>
using namespace std;

int main() {

	int dlugosc = 0;

	cin>>dlugosc;

	string tab[dlugosc];
	for(int i=0; i<dlugosc ;i++){
		cin>>tab[i];
	}

	for(int i=0; i<dlugosc ;i++){
		string s = tab[i];
        string s2 = s.substr(0,(s.length())/2);
        cout<<s2<<endl;
	}

	return 0;
}

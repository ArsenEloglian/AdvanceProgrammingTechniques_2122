#include <iostream>
#include <string>

using namespace std;

int main() {

	int iloscTestow;
	cin >> iloscTestow; 
	
	for(int j=0; j<iloscTestow;j++){
			
		string napis;
		cin >> napis;
		int counter = 1;
		int i;
	
		for (i = 1;i <= napis.length();i++) {
			
			if (napis[i] != napis[i-1]) {
	
				if (counter > 2) {
					cout << napis[i-1] << counter;
				}
				else if (counter == 2) {
					cout << napis[i-1] << napis[i-1];
				}
				else
					cout << napis[i-1];
				counter = 1;
			}
			else
				counter++;	
		}
		cout<<"\n"; 
	} 
}

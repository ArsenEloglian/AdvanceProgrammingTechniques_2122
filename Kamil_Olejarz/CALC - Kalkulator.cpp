#include <iostream>

using namespace std; 

int main(){
	
	char znak; 
	int x,y; 
	
	while(!(cin>>znak).eof()){
		
		cin>>x;
		cin>>y; 
		
		if(znak=='+')
			cout <<x+y<<endl;
		else if(znak=='-')
			cout <<x-y<<endl;
		else if(znak=='*')
			cout <<x*y<<endl;
		else if(znak=='/')
			cout <<x/y<<endl;
		else if(znak=='%')
			cout <<x%y<<endl;
	}
}

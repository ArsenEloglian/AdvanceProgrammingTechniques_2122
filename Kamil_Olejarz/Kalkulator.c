#include <stdio.h>
#include <stdlib.h>


int suma(int a, int b){
	
	int suma = a+b; 
	return suma; 
}

int roznica(int a, int b){
	
	int roznica =  a-b; 
	return roznica;
}

int iloczyn(int a, int b){
	
	int iloczyn = a*b;
	return iloczyn;  
}

int iloraz(int a, int b){
	
	int iloraz;
	iloraz = a/b; 

	return iloraz; 
}

int modulo(int a, int b){
	
	int modulo = a%b; 
	return modulo; 
}

int main(){
	
	int wynik; 
	float wynik1; 
	int a; 
	int b;
	char c;
	int i=0; 
	
	
	while(i<=100){
		
		scanf("%c %d %d", &c, &a, &b);
		
		if(c=='+'){
			
			wynik = suma(a,b); 
			printf("%d\n", wynik);
			fflush(stdin);
		}else if(c=='-'){
			
			wynik = roznica(a,b); 
			printf("%d\n", wynik);
		}else if(c=='*'){
			
			wynik = iloczyn(a,b); 
			printf("%d\n", wynik);
		}else if(c=='%'){
			
			wynik = modulo(a,b); 
			printf("%d\n", wynik);

		}else if(c=='/'){
			
			wynik = iloraz(a,b); 
			printf("%d\n", wynik);
		}
		
		i++; 
		fflush(stdin);
	}
	
	return 0; 
}

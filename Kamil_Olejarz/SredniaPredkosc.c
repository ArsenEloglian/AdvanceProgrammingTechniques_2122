#include <stdio.h>
#include <stdlib.h>
 
 
int sredniaPredkosc(int v1, int v2){
	
	
	int sredniaPredkosc = (2*(v1*v2)/(v1+v2));
	return sredniaPredkosc;
}
 
 
int main(){
	
	int t; 
	scanf("%d", &t);
	
	int i;
	int v1; 
	int v2; 
	int wyniki[t];
	
	if(t>=1 && t<10000){
 
	
		for(i=0;i<t;i++){
		
			scanf("%d %d", &v1, &v2);
			int srednia = sredniaPredkosc(v1, v2); 
			wyniki[i] = srednia; 
		}
		
		int j; 
		
		for(j=0; j<t;j++){
			
			printf("%d \n", wyniki[j]);
		}
		
		return 0; 
	}else
		return 1; 
	
		
 
	
	
	
}

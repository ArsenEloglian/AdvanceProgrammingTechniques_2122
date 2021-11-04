#include <stdlib.h>
#include <stdio.h>

int main(){
	
	int i; 
	int j; 
	int liczba; 
	int suma; 
	int liczbaTestow; 
	int n; 	


	scanf("%d", &liczbaTestow);
	
	for(i=0; i<liczbaTestow;i++){
		
		
		n = 0; 
		liczba = 0;
		suma  = 0; 
		
		
		scanf("%d", &n);
		for(j=0; j<n;j++){
			
			scanf("%d", &liczba);
			
			suma = suma + liczba; 				
		}
		
		printf("%d\n", suma); 
		
		
		
	}
	
	return 0; 	
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	FILE* fp = fopen("in.txt", "r");
	int countOfLines = 0;
	char c;

	if(fp!=NULL){
		while(!feof(fp)){
			c = getc(fp);
			if(c=='\n'){
				countOfLines++;
			}
		}
		fclose(fp);
	}else{
		printf("Error");
		return 1;
	}

	printf("%d",countOfLines);


	return 0;
}

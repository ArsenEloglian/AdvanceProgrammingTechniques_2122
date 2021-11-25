#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n1 = 0;
	int n2 = 0;
	int k1 = 0;
	int k2 = 0;
	int iloscMiejsc = 0;

	scanf("%d %d %d %d",&n1,&k1,&n2,&k2);

	if(n1>=1 && k1<=1000 && n2<=1000 && k2<=1000){

		iloscMiejsc = n1*k1 + n2 * k2;
		printf("%d", iloscMiejsc);
	}else{
		return 1;
	}

	return 0;
}

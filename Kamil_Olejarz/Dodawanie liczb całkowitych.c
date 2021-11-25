#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c, suma;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	if (a <= 100 && b <= 100 && c <= 100) {
		suma = a + b + c;
		printf("%d", suma);
		return 0;
	}
	else
		return 1;
}

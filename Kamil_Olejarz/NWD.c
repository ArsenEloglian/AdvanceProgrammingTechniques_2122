#include <stdio.h>
#include <stdlib.h>

int nwd(int a, int b) {
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int main() {
	int wynik, a, b, t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);

		if ((a >= 0 && a <= 1000000) && (b >= 0 && b <= 1000000)) {
			wynik = nwd(a, b);
			printf("%d\n", wynik);
		}
	}
}

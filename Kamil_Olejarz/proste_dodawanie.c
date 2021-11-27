#include <stdlib.h>
#include <stdio.h>

int main() {
	int i, j, n, liczba, suma, liczbaTestow;

	scanf("%d", &liczbaTestow);

	for (i = 0; i < liczbaTestow; i++) {
		n = liczba = suma = 0;

		scanf("%d", &n);
		
		for (j = 0; j < n; j++) {
			scanf("%d", &liczba);
			suma = suma + liczba;
		}

		printf("%d\n", suma);
	}
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int liczba, flag, t, i, j;

	scanf("%d", &t);

	if (t >= 1 && t < 100000) {
		for (i = 0; i < t; i++) {
			flag = 0;
			scanf("%d", &liczba);

			for (j = 1; j <= liczba; j++) {
				if (liczba % j == 0) {
					flag++;
				}
			}
			if (flag == 2) {
				printf("TAK\n");
			}
			else {
				printf("NIE\n");
			}
		}
		return 0;
	}
	else {
		return 1;
	}
}

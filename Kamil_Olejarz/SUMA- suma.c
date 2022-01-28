#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j=0, k;
    while(scanf("%d", &i) != EOF){
        j+=i;
        printf("%d\n",j);
    }
}

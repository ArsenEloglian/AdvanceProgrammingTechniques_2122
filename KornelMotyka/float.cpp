#include<iostream>
#include <stdio.h>

using namespace std;

void printfloat(float x);
int main(){

  int t;
  float x;

  scanf("%d",&t);
  while(t){


	scanf("%f",&x);
	//x = float(x);

	printfloat(x);

  t--;
  }
  return 0;
}

void printfloat(float x){
  int i;

  for (i = sizeof x-1; i>=0; --i)
	printf("%x ",(((const unsigned char*)&x)[i]));

  printf("\n");
}

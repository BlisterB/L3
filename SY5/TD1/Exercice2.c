#include <stdio.h>
#include <stdlib.h>

void swap(int* p1, int* p2){
	int tampon;
	tampon = *p1;
	*p1 = *p2;
	*p2 = tampon;
}

void affiche(int a, int b){
	printf("a : %d, b : %d\n", a, b);
}

int main(void){
	int a = 1, b = 2;
	affiche(a,b);
	swap(&a,&b);
	affiche(a,b);
	
	return 1;
}

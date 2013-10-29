#include <stdio.h>
#include <stdlib.h>

int main(void){
	printf("Entrez ce que vous voulez, un point signifie l'arret de la saisie");
	char c;
	do{
		c = getchar();
		printf("%c", c);
	}while(c != '.');
	printf("Arret de la saisie");
	
	return 1;
}

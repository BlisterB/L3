#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LB 100

void affiche(FILE *ptr, int* compteur, int affichage_ligne){
	char buffer[LB];
	char *p;
		
	while(fgets(buffer, LB, ptr) != NULL){
		p = buffer;
		while(*p != '\n'){
			p++;
		}
		if(*p == '\n'){
			(*compteur)++;
			if(affichage_ligne == 1)
				printf("%d ", *compteur);
		}
		fputs(buffer, stdout);
	}
}

int main(int argc, char* argv[]){
	int compteur = 0;
	int taille_tab = argc;
	int affichage_ligne = 0;
	if(taille_tab != 1){
		while(taille_tab != 1){
			if(!(strcmp(argv[argc - 1], "-n"))){
				affichage_ligne = 1;
				break;
			}
			taille_tab--;
		}
	}
	if(argc != 1){
		while(argc > 1){
			if(!(strcmp(argv[argc - 1], "-n"))){
				argc--;
			}
			else{
				affiche(fopen(argv[argc - 1], "r"), &compteur, affichage_ligne);
				argc--;
			}
		}
	}
	else
		affiche(stdin, &compteur, affichage_ligne);
	return 0;
}

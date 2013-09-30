#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* itineraire(char* rep1, int n1, char* rep2, int n2){
	//1 / On va comparer les chaines jusqu'à obtenir un caractère différent (ie le moment ou leurs chemin absolu sont différent)
	//2 / A partir de ce caractère on compte le nombre de '/' de rep1 ie le nombre de dossier à remonter
	//3 / On va ensuite coller le chemin de rep2 à partir de ce caractère
	
	char* chemin = malloc(sizeof(char) * (n1+n2) + 1);
		
	//1
	int compteur = 1;
	char *p1 = rep1, *p2 = rep2;
	while(*p1++ && *p2++){
		if(*p1 == *p2) compteur++;
		else break;
	}
	
	//2
	int compteur_slash = 1;
	while(*p1){
		if(*p1 == '/')
			compteur_slash++;
		p1++;
	}
	
	//3
	int i;
	char *p = chemin;
	//Creation des "retour en arriere"
	for(i = 0; i < compteur_slash; i++){
		*p = '.';
		p++;
		*p = '.';
		p++;
		*p = '/';
		p++;
	}
	//Copie de la partie différente de rep2
	while(*p2){
		*p = *p2;
		p++;
		p2++;
	}
	*p = '\0';
	return chemin;
}

int main(void){
	char *rep1 = "/mehdi/SY5/tp1/rep1", *rep2 = "/mehdi/AL3/TP6/rep2";
	char *chemin = itineraire(rep1, strlen(rep1), rep2, strlen(rep2));
	
	printf("%s\n", chemin);
	
	return 1;
}

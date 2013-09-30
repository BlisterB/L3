#include <stdio.h>
#include <stdlib.h>

//n est le nombre de colonne, m le nombre de ligne

int* creation_tableau(int n, int m){
	int* tab = calloc(n*m, sizeof(int));
	return tab;
}

void afficher_ligne(int* tab, int n, int m, int ligne){
	printf("Ligne numéros %d :\n", ligne);
	int i;
	for(i = 0; i < m; i++){
		printf("%d ", *(tab + (i + ligne*m))); //Ou tab[i + ligne*m]
	}
	putchar('\n');
}

void afficher_colonne(int* tab, int n, int m, int colonne){
	printf("Colonne numéros %d :\n", colonne);
	int i;
	for(i = 0; i < n; i++){
		printf("%d\n", *(tab + (i + colonne*n)));
	}
	putchar('\n');
}

int main(void){
	int* tab = creation_tableau(5, 4);
	afficher_ligne(tab, 5, 4, 0);
	afficher_colonne(tab, 5, 4, 0);
	
	return 1;
}

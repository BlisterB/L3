#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* tab;
	int longueur;
} permutation;

void applique_permutation(permutation p, int *t){
	//On va créer un tableau qui contiendra les valeurs bien ordonée
	int tab[p.longueur];
	int i;
	for(i = 0; i < p.longueur; i++){
		tab[p.tab[i]] = t[i];
	}
	//On remplace les valeurs d'origine par les nouvelles valeur (on ne peut pas remplacer les pointeurs car on n'a pas importé int **t)
	for(i = 0; i < p.longueur; i++){
		t[i] = tab[i];
	}
}

void tri(int *t, int lg){
	//Calcul de la permutation
	permutation perm;
	perm.longueur = lg;
	perm.tab = malloc(sizeof(int) * lg);
	
	int i, j, nb;
	for(i = 0; i < lg; i++){
		nb = 0;
		for(j = 0; j < lg; j++){
			if(t[j] < t[i]) nb++;
		}
		perm.tab[i] = nb;
	}
		
	//Application de la permutation
	applique_permutation(perm, t);
}

void affiche_tableau(int* tab, int n){
	int i;
	for(i=0; i < n; i++){
		printf("%d, ", tab[i]);
	}
	putchar('\n');
}

int main(void){
	//Initialisation de la permutation
	permutation perm;
	perm.longueur = 5;
	int permutation[] = {3, 1, 4, 2, 0};
	perm.tab = permutation;
	
	//
	int tab[] = {12, 4, 23, 1, 7};
	affiche_tableau(tab, 5);
	printf("Permutation :\n");
	applique_permutation(perm, tab);
	affiche_tableau(tab, 5);
	printf("Tri :\n");
	tri(tab, 5);
	affiche_tableau(tab, 5);
	
	return 1;
}

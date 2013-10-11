//Mehdi KHELIFI Groupe INFO 2

#include <stdio.h>
#include <stdlib.h>


typedef struct{
	unsigned int taille;
	int *tab;
}ensemble;

ensemble* allouer_ensemble(int taille);
void liberer_ensemble(ensemble* ens);
int membre_ensemble(ensemble *ens, int nombre);
void demande_membre_ensemble(ensemble *ens);
void demande_membre_ensemble(ensemble *ens);
ensemble* saisir_ensemble(void);
void tri_tableau(int* tab, int n);
void affiche_ens(ensemble* ens);
void affiche_ensemble(ensemble* ens);
ensemble* union_ensembles(ensemble* ens1, ensemble* ens2);


//EXERCICE 1 : Alloue l'espace necessaire pour stocker un ensemble ainsi que son tableau, renvoie le pointeur sur cet ensemble
ensemble* allouer_ensemble(int taille){
	ensemble *ens = malloc(sizeof(ensemble));
	ens->taille = taille;
	int *tab = calloc(taille, taille * sizeof(int));
	ens->tab = tab;
	
	return ens;
}

//EXERCICE 1 : Libere l'espace occupé par l'ensemble ainsi que son tableau
void liberer_ensemble(ensemble* ens){
	free(ens->tab);
	free(ens);
}

//EXERCICE 2 : Teste si l'entier "nombre" est présent dans l'ensemble "ens"
int membre_ensemble(ensemble *ens, int nombre){
	int* tab = ens->tab;
	int i;
	for(i = 0; (i < ens->taille) && (tab[i] <= nombre) ; i++){//Le tableau est trié, d'ou la condition tab[i] <= nombre
		if(tab[i] == nombre)
			return 1;
	}
	return 0;
}

//Demande a l'utilisateur d'entrer un nombre a tester puis utiliser la fonction membre_ensemble ci dessus
void demande_membre_ensemble(ensemble *ens){
	int nombre = 0;
	int erreur = 0;
	printf("Entrer une valeur pour tester si elle est présente dans cet ensemble?\n");
	erreur = scanf("%d", &nombre);
	if(erreur != 1){//Si l'utilisateur a fait une saisie non numérique
		printf("La valeur que vous avez saisie n'est pas correcte.\n");
	}
	else{
		if(membre_ensemble(ens, nombre))
			printf("Oui, cette valeur est contenu dans l'ensemble!\n");
		else
			printf("Non, cette valeur n'est pas contenu dans l'ensemble\n");
	}
}

/* EXERCICE 3 :
 * Initialise un ensemble et renvoie un pointeur sur cet ensemble après avoir demandé a l'utilisateur sa taille et son contenu
 * Trie egalement le tableau de cette ensemble (comme stipulé dans l'énoncé) */
ensemble* saisir_ensemble(void){
	int nombre = 0;
	int erreur = 0;
	printf("Combien d'éléments doit contenir l'ensemble ?\n");
	erreur = scanf("%d", &nombre);
	if(erreur != 1){//Si l'utilisateur a fait une saisie non numérique
		printf("La valeur que vous avez saisie n'est pas correcte.\n");
		return NULL;
	}
	else{
		if(nombre <= 0){
			printf("Cette valeur est incorrecte\n");
			return NULL;
		}
		ensemble* ens = allouer_ensemble(nombre);
		printf("Nous avons créé un ensemble de %d élément(s), veuillez le remplir : \n", nombre);
		int i;
		for(i = 0; i < nombre; i++){
			printf("Valeur de l'élément #%d :\n", i+1);
			erreur = scanf("%d", &((ens->tab)[i]));
			if(erreur != 1){//Si l'utilisateur a fait une saisie non numérique
				printf("La valeur que vous avez saisie n'est pas correcte.\n");
				return NULL;
			}
		}
		tri_tableau(ens->tab, ens->taille);
		return ens;
	}
}

//Tri le tableau tab de taille n, on utilise ici le tri par selection
void tri_tableau(int* tab, int n){
	int i, j, tampon;
	int min;
	for(i=0; i < n - 1 ; i++){
		min = i;
		for(j = i; j < n; j++){
			if(tab[j] < tab[min])
				min = j;
		}
		if(min != i){
			tampon = tab[i];
			tab[i] = tab[min];
			tab[min] = tampon;
		}
	}
}

//EXERCICE 4 : Affiche un ensemble
void affiche_ensemble(ensemble* ens){
	printf("Affiche de l'ensemble : ");
	int i;
	for(i = 0; i <= (ens->tab)[(ens->taille)-1]; i++){
		if(membre_ensemble(ens, i))
			printf("*");
		else
			printf("_");//On utilise des '_' au lieu d'un espace par souci de lisibilité
	}
	putchar('\n');
}

//Affiche l'ensemble sous forme numérique (non demandé dans l'exercice)
void affiche_ens(ensemble* ens){
	int i;
	int* tab = ens -> tab;
	printf("Affichage de l'ensemble :\n");
	for(i = 0; i < ens -> taille; i++){
		printf(" %d ", tab[i]);
	}
	putchar('\n');
}

/*EXERCICE 5 : Cree un ensemble contenant l'union de ens1 et ens2, renvoie un pointeur sur cet ensemble*/
ensemble* union_ensembles(ensemble* ens1, ensemble* ens2){
	ensemble* ens_union = allouer_ensemble((ens1->taille) + (ens2->taille));
	int i, j = 0;//j est l'indice de ens_union, il joue le role de pointeur
	int ajout_zero = 0;//Cette variable va nous servir à savoir si on a ajouté un zero au tableau (0 étant le contenu d'un tableau non rempli par calloc, ce qui fausse les test)
	//Ajout des elements de ens1
	for(i = 0; i < (ens1->taille); i++){
		if(!(membre_ensemble(ens_union, (ens1->tab)[i]))){
			(ens_union->tab)[j] = (ens1->tab)[i];
			j++;
		}
		if(((ens1->tab)[i]) == 0 && ajout_zero == 0){
			j++;
			ajout_zero = 1;
		}
	}
	//Ajout des elements de ens2
	for(i = 0; i < (ens2->taille); i++){
		if(!(membre_ensemble(ens_union, (ens2->tab)[i]))){
			(ens_union->tab)[j] = (ens2->tab)[i];
			j++;
		}
		if(((ens2->tab)[i]) == 0 && ajout_zero == 0){
			j++;
			ajout_zero = 1;
		}
	}
	//Tri de ens_union
	//On modifie la taille de ens_union en tenant compte du nombre d'element qu'on lui a rajouté
	ens_union->taille = j;
	//On pourrait ici utiliser realloc de cette maniere :
	//ens_union->tab = realloc(ens_union->tab, sizeof(int)*(ens_union->taille));
	//MAIS je ne le fais pas car le gain en terme d'espace dans la mémoire est négligeable face à
	//la perte en complexité temporelle de realloc, de plus realloc peut dans de rare cas revoyer un
	//pointeur NULL.
	//Ici, je ne change que la propriété "taille" de l'ensemble "ens_union", le tableau contiendra
	//donc les valeurs non redondante triée jusqu'à l'indice "ens_union-> taille - 1", les cases
	//suivante resteront initialisée à 0 et ne seront pas appelées.
	tri_tableau(ens_union->tab, ens_union->taille);
	
	return ens_union;
}

int main(void){
	//Saisie du premier ensemble
	printf("**SAISIE DU PREMIER ENSEMBLE**\n");
	ensemble* ens1 = saisir_ensemble();
	if(ens1 != NULL){
		affiche_ensemble(ens1);
		demande_membre_ensemble(ens1);
		putchar('\n');

	
		//Saisie du second ensemble
		printf("**SAISIE DU SECOND ENSEMBLE**\n");
		ensemble* ens2 = saisir_ensemble();
		if(ens2 != NULL){
			affiche_ensemble(ens2);
			demande_membre_ensemble(ens2);
			putchar('\n');
		
			//Calcul de l'union
			
			printf("**CALCUL DE L'UNION DE CES DEUX ENSEMBLES**\n");
			ensemble* ens_union = union_ensembles(ens1, ens2);
			if(ens_union !=NULL){
				affiche_ensemble(ens_union);
				demande_membre_ensemble(ens2);
				
				liberer_ensemble(ens_union);
			}
			liberer_ensemble(ens2);
		}
		liberer_ensemble(ens1);
	}

	return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct{
	size_t nb_elts;
	size_t taille_elt;
	double debut;
}metatab;

//On renvoie un pointeur sur char car char correspond à la plus petite unité de mémoire
//(taille de 1 seul octet) et offsetof marche par "unité" de 1 (1 octet)
char* metadonnees_tab(void *tab){ 
	 return (char *) tab - offsetof(metatab, debut);
}

size_t nombre_elts(void *tab){
	return *((size_t*)metadonnees_tab(tab));
	//OU (moins ambigue)
	/*
	 * metatab *p;
	 * p = (metatab *)metadonnee_tab(tab);
	 * return p -> nb_elts
	 */
}

size_t  taille_elt(void* tab){
	metatab *p;
	p = (metatab*)metadonnees_tab(tab);
	return p -> taille_elt;
}

void * allocation(size_t nb_elts, size_t taille_elts){
	char *t;
	metatab *p;
	t = malloc(nb_elts*taille_elts + offset(metatab, debut));
	p = (metatab *)t;
	p->nb_elts = nb_elts;
	p->taille_elt;
	t = t + offsetof(metatab, debut);
	memset(t, '\0', nb_elts * taille_elt);
	return t;
}

void reallocation(void *tab, int nb){
	struct metatab *p;
	size_t nb;
	if(nb_elem <= 0)
		free(metadonnees_tab(t));
	int nb = nb_elts(t);
	if(nb_elts == nb)
		return t;
	p = realloc(metadonnee(t), nb * taille_elts(t) + offesetof(metatab, debut))
	if(p == NULL)
		return NULL;
	p->nb_elts = nb_elts;
	if(nb_elts > nb)
		memset((char *p) + offsetof(metatab, debut) + p -> taille_elt * nb, '\0', (nb_elts - nb) * p -> taille_elt);
}
int main(void){

	return 1;
}

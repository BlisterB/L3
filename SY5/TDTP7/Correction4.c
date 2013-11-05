/* 
 * n <- taille/256
 * On lance n processus fils
 * Le processus fils i appelle une fonction sous-recherche et renvoie le nombre d'occurences exit(nb_occurence)
 * Le processus pere recupere la valeurs renvoyée par chaque fils et fait une somme de toutes les valeurs
*/


int recherche(int *tab, int size, int v){
	int i = 0;
	int n = size/256;
	int pid;
	int occ = 0;
	int stour;
	while(i <= n && (pid = fork()))
		i++;
	if(!pid){
		occ = sous_recherche(tab = i * 256 + min (256, size - i*256), v);
		exit(occ);
	}
	for(i = 0; i <= n; i++){
		init(&retour)
		occ += EXITSTATUS(retour);
	}
	return occ;
}

int sous_recherche(int *debut, int *fin, int v){
	int i;
	int occ;
	for(i=0; i < fin-debut; i++){
		if(*(debut++) == v)
			occ++;
	}
	return occ;
}

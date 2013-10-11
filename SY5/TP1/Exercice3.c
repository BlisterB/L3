#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* chaine;
	int frequence;
} stat_mot;

int nb_apparition_mot(char* chaine, char* mot, int lg_mot){
	int compteur_lg = 0, compteur_apparition = 0;
	char* p = chaine;
	while(*p){
		compteur_lg++;
		if(*(p+1) == ' ' || *(p+1) == '\0'){
			if(strncmp(p - compteur_lg + 1, mot, compteur_lg) == 0){
				compteur_apparition++;
			}
			compteur_lg = 0;
		}
		do{
			p++;
		}while(*p == ' ');
	}
	
	return compteur_apparition;
}


//Renvoie la longueur du premier mot de la chaine avant un espace ou la fin de la chaine
int lg_mot(char* chaine){
	int compteur = 0;
	while(*chaine != ' ' && *chaine != '\0'){
		compteur++;
		chaine++;
	}
	
	return compteur;
}

//Vérifie si le mot est dans le tableau et augmente sa fréquence si c'est le cas (puis renvoie 1), l'insere dans le tableau le cas échéant et retourn 0
int mot_dans_tab(stat_mot** tab, int *lg_tab, char* chaine, int lg_mot){
	int i;
	for(i = 0; i < *lg_tab; i++){
		if(!strncmp((*tab + i)->chaine, chaine, lg_mot)){ //Le mot est présent dans le tableau
			((*tab + i)->frequence)++;
			return 1;
		}
	}
	//Le mot n'est pas présent dans le tableau
	*tab = realloc(*tab, sizeof(stat_mot) * (*lg_tab + 1));
	char* mot = (char*)malloc((lg_mot + 1) * sizeof(char));
	strncpy(mot, chaine, lg_mot);
	mot[lg_mot] = '\0';
	(*tab + *lg_tab)->chaine = mot;
	(*tab + *lg_tab)->frequence = 1;
	(*lg_tab)++;
	
	return 0;
}

int mot_le_plus_frequent(char* chaine, int lg_mot_chaine){
	stat_mot* tab = NULL;
	int lg_tab = 0;
	
	int lg_mot_pointe;
	//1 - On déroule la chaine et on stocke tous les mots de lg supérieure ou égale à lg_mot
	while(*chaine){
		lg_mot_pointe = lg_mot(chaine);
		if (lg_mot_pointe >= lg_mot_chaine){
			mot_dans_tab(&tab, &lg_tab, chaine, lg_mot_pointe);
		}
		chaine += lg_mot_pointe;
		//On passe la zone de ' '
		while(*chaine == ' '){
			chaine++;
		}
	}
	
	printf("\nFrequence des mots :\n");
	int i;
	for(i = 0; i < lg_tab; i++){
		printf("%s %d\n", (tab[i]).chaine, (tab[i]).frequence);
	}
	
	return 1;
}

int main(void){
	char* c = "King in the North ! King in the fucking North !";
	char* mot = "Lord";
	int compteur = nb_apparition_mot(c, mot, strlen(mot) + 1);
	printf("Chaine : %s\nElle comporte %d occurence(s) de \"%s\"\n", c, compteur, mot);
	
	mot_le_plus_frequent(c, 3);
	
	return 1;
}

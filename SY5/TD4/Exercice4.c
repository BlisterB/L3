#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define LB 100

int remplace(char *chemin1, char *chemin2, char a, char b){
	int desc1, desc2;
	int lus, i, nb_char = 0;
	char buffer[LB];
	
	desc1 = open(chemin1, O_RDONLY);
	desc2 = open(chemin2, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	if(desc1 == -1 || desc2 == -1){
		printf("Probleme dans l'ouverture des fichiers\n");
		return 0;
	}
	
	while((lus = read(desc1, buffer, LB)) > 0){
		nb_char += lus;
		//Parcours du Buffer et modification des char a en char b
		for(i = 0; i < LB; i++)
			if(buffer[i] == a)
				buffer[i] = b;
		
		//Ecriture du Buffer dans le deuxieme descripteur
		write(desc2, buffer, lus);
	}
	
	ftruncate(desc2, nb_char * sizeof(char));
	
	close(desc1);
	close(desc2);
	
	printf("La fonction s'est déroulée avec succes\n");
	return 1;
}

int supprimer(char *chemin1, char *chemin2, char a){
	int desc1, desc2;
	int lus, i, j, nb_a, nb_char = 0;
	char buffer[LB];		
		
	desc1 = open(chemin1, O_RDONLY);
	desc2 = open(chemin2, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	
	
	if(desc1 == -1 || desc2 == -1){
		printf("Probleme dans l'ouverture des fichiers\n");
		return 0;
	}
	
	while((lus = read(desc1, buffer, LB)) > 0){
		//Parcours du buffer et suppression des char a
		nb_a = 0;
		for(i=0; i < LB; i++){
			while(buffer[i] == a){
				nb_a++;
				for(j = i; j < LB - 1; j++)
					buffer[j] = buffer[j+1];
			}
		}
		write(desc2, buffer, lus - nb_a);
		nb_char += lus - nb_a;
	}
	
	ftruncate(desc2, nb_char*sizeof(char));
	
	close(desc1);
	close(desc2);
	
	printf("La fonction s'est déroulée avec succes\n");
	return 1;
}

int main(int argc, char *argv[]){
	int i, j = 0, pos_option = 0; 
	char *argument[4] = {NULL, NULL, NULL, NULL};
	
	//Test du nombre d'arguement
	if(argc != 5){
		printf("Le nombre d'argument n'est pas valide\n");
		return 0;
	}
	printf("Nombre d'argument OK\n");
	
	//Test de la presence de -d
	for(i = 1; i < 5; i++){
		if(strcmp("-d", argv[i]) == 0){
			printf("L'option -d est detectee\n");
			pos_option = 1;
		}
		else
			argument[j++] = argv[i];
	}
	
	//Appel de la fonction adequate
	if(pos_option == 0){
		int taille_a = strlen(argument[2]), taille_b = strlen(argument[3]);
		if(taille_a != 1 || taille_b != 1){
			printf("L'argument 3 ou 4 n'est pas un caractere\n");
			return 0;
		}
		printf("Appel de la fonction de remplacement\n");
		return remplace(argument[0], argument[1], *(argument[2]), *(argument[3]));
	}
	else{
		int taille_a = strlen(argument[2]);
		if(taille_a != 1){
			printf("L'argument 3 n'est pas un caractere\n");
			return 0;
		}
		else{
			printf("Appel de la fonction de suppression\n");
			return supprimer(argument[0], argument[1], *(argument[2]));
		}
	}
	
	return 1;
}

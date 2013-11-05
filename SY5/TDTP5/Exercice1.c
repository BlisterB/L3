#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int f(char* chemin, int optionI, int optionS){
	DIR *rep = NULL;
	struct dirent* ent = NULL;
	struct stat s;
	
	rep = opendir(chemin);
	if(rep == NULL){
		printf("Erreur dans l'ouverture du dossier\n");
		exit(-1);
	}
	
	printf("%s\n", chemin);
	while((ent = readdir(rep))){
		if((optionI == 0) && (optionS == 0)){
			printf("| %s\n", ent->d_name);
		}
		else if((optionI == 1) && (optionS == 0)){
			printf("| %s i = %d\n", ent->d_name, (int)(ent->d_ino));
		}
		else{//Option s activée
			if(!(stat(ent->d_name, &s)))
				printf("| %s taille = %d\n", ent->d_name, (int)(s.st_blocks));
			else
				printf("Erreur dans la creation de stat\n");
		}
	}
	
	closedir(rep);
	return 1;
}

int main(int argc, char** argv){
	int i, optionI = 0, optionR = 0, optionS = 0;
	char* chemin = NULL;
	//Test des arguments
	if(argc < 2){
		printf("Erreur dans le nombre d'arguments\n");
		exit(-1);
	}
	for(i = 1; i < argc; i++){
		if(!strcmp(argv[i], "-i")){
			printf("Detection de l'argument -i\n");
			optionI = 1;
		}
		else if(!strcmp(argv[i], "-s")){
			printf("Detection de l'argument -s\n");
			optionS = 1;
		}
		else if(chemin != NULL){
			printf("Trop d'argument !\n");
			exit(-1);
		}
		else
			chemin = argv[i];
	}
	
	//Envoie aux fonctions
	if((!optionR) && chemin)
		f(chemin, optionI, optionS);
	
	
	return 1;
}

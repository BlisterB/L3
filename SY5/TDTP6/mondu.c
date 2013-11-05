#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/*NOTE
 * Les appels de st_blocks semblent doubler la tailler des blocs par rapport
 * à la commande du. 
 */

/*Fonction mondu */
int mondu(char *chemin, int afficher_fichier){
	int compteur = 0;
	char* nouveau_chemin;
	struct stat ent;
	DIR* dir;
	struct dirent* p_dirent;
	
	//Creation de la structure stat et initialisation du compteur de bloc
	if((stat(chemin, &ent)) < 0){
		printf("Erreur dans le chargement des information de l'i-noeud de %s\n", chemin);
		return 0;
	}
	
	compteur = (int)ent.st_blocks;
	//Si le chemin est un fichier, on affiche son nombre de bloc seulement si c'est le premier appel de mondu
	if(S_ISREG(ent.st_mode)){
		if(afficher_fichier)
			printf("%d\t%s\n", compteur, chemin);
	}
	
	//Si le chemin est un dossier, on affiche le nombre de blocs de son arbo puis de lui même
	else if(S_ISDIR(ent.st_mode)){
		//On deroule la fonction sur la sous arborescence du chemin courant
		if((dir = opendir(chemin)) == NULL){
			printf("**Erreur dans l'ouverture de %s**\n", chemin);
			return 0;
		}
		while((p_dirent = readdir(dir)) != NULL){
			if(strcmp(p_dirent->d_name, ".") && strcmp(p_dirent->d_name, "..")){//On ignore . et ..
				nouveau_chemin = (char*)malloc((strlen(chemin) + strlen(p_dirent->d_name) + 2) * sizeof(char));
				
				strcpy(nouveau_chemin, chemin);
				if(nouveau_chemin[strlen(nouveau_chemin) - 1] != '/')
					strcat(nouveau_chemin, "/");
				strcat(nouveau_chemin, p_dirent->d_name);
				
				compteur += mondu(nouveau_chemin, 0);
				
				free(nouveau_chemin);
			}
		}
		
		//On affiche les stats obtenus
		printf("%d\t%s\n", compteur, chemin);
		
		closedir(dir);
	}
	
	return compteur;
}

int main(int argc, char** argv){
	//Test des arguments
	if(argc > 2){
		printf("**Il y a trop d'arguments. La commande doit être entrée sur la forme mondu ref et vous avez entré %d arguments.**\n", argc);
		exit(-1);
	}
	
	//Envoie vers la fonction
	if(argc == 1){
		puts("**Comme ref n'est pas spécifié, on lance mondu dans le dossier courant**");
		mondu(".", 1);
	}
	else
		mondu(argv[1], 1);

	return 1;
}

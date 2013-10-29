#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LB 3000000

typedef struct {
	int red :8;
	int green :8;
	int blue :8;
}pixel;

typedef struct {
	int row_nb;
	int column_nb;
	int intensity;
	pixel * tab;
}image;

image* allouer_image(int ligne, int colonne){
	image* p = (image*)malloc(sizeof(image));
	p->row_nb = ligne;
	p->column_nb = colonne;
	p->intensity = 255;
	p->tab = malloc(ligne*colonne*sizeof(pixel));
	
	return p;
}

//Renvoie le prochain nombre du string avant un espace ou une fin de caractere et remplie taille_nombre avec la taille du nombre
int prochain_nombre(char *c, int *taille_nombre){
	while(*c && *c == ' '){
		c++;
	}
	//On compte le nombre de caractere du prochain nombre
	char *p = c; int compteur = 0;
	while(*p && (*p != ' ' && *p != '\n')){
		compteur++; p++;
	}
	*taille_nombre = compteur;
	
	int nombre = 0; int puissance = 1; int i;
	//On interprete les nombres
	while(*c && (*c != ' ' && *c != '\n')){
		for(i = 1; i < compteur; i++){
			puissance *= 10;
		}
		nombre += (*c - 48)*puissance;
		compteur--;
		puissance = 1;
		c++;
	}
	
	return nombre;
}

image* ppm_to_image(const char* path){
	image *im;int taille_nb;

	char buffer[LB];//On initialise le buffer
	FILE* file = fopen(path, "r");//Ouverture du flot
	if (file == NULL){ //Exception : erreur d'ouverture
		printf("Erreur dans l'ouverture du fichier\n");
		return NULL;
	}
	
	//1ere ligne
	if(fgets(buffer, LB, file) != NULL){//Chargement de la premiere ligne dans le buffer;
		if(strcmp(buffer, "P6\n") != 0){//La premiere ligne est éronnée
			printf("Premiere ligne erronee\n");
			return NULL; 
		}
	}
	else{//Le fichier ne contient rien
		printf("Le fichier est vide\n");
		return NULL;
	}
	printf("Premiere ligne conforme\n");
	
	int ligne, colonne;
	//2eme ligne
	if(fgets(buffer, LB, file) != NULL){//Chargement de la deuxieme ligne dans le buffer;
		printf("%s\n", buffer);
		int taille_nb = 0;
		ligne = prochain_nombre(buffer, &taille_nb);
		colonne = prochain_nombre(buffer + taille_nb, &taille_nb);
		printf("Deuxieme ligne conforme -> lignes : %d, colonnes : %d\n", ligne, colonne);
		
		im = allouer_image(ligne, colonne);
		printf("PPM créé, propriété :\n\tLignes : %d\n\tColonnes : %d\n\tIntensité : %d\n", im->column_nb, im->row_nb, im->intensity);
	}
	else{
		printf("Pas de deuxieme ligne\n");
		return NULL;
	}
	
	//3eme ligne
	if(fgets(buffer, LB, file) != NULL){//Chargement de la deuxieme ligne dans le buffer;
		im->intensity = prochain_nombre(buffer, &taille_nb);
		printf("Troisieme ligne conforme :\nPPM créé, propriété :\n\tLignes : %d\n\tColonnes : %d\n\tIntensité : %d\n", im->column_nb, im->row_nb, im->intensity);
	}
	else{
		printf("Pas de troisieme ligne\n");
		return NULL;
	}
	
	//4eme ligne
	int compteur = 0, i;
	while(fgets(buffer, LB, file) != NULL){
		for(i=0; (i < LB) && buffer[i] != '\n' ; i+=3){
			((im->tab)[compteur]).red = buffer[i];
			((im->tab)[compteur]).green = buffer[i+1];
			((im->tab)[compteur]).blue = buffer[i+2];

			compteur++;
		}
	}
	
	printf("Envoie du pointeur\n");
	return im;
}

int puissance(int n, int p){
	if (p == 0)
		return 1;
	int i;
	for(i=1; i < p; i++){
		n *= n;
	}
	return n;
}

void copier_nombre(char *p, int nombre){
	int taille_nb = 0;
	int cp_nombre = nombre;
	//Taille 
	while(cp_nombre>0){
		cp_nombre/=10;
		taille_nb++;
	}
	printf("Debut de la copie");
	//Copie du nombre
	int i;
	for(i = taille_nb; i > 0; i--){
		*p = (nombre / puissance(10, i-1)) + 48;
		nombre%=puissance(10, i-1);printf("%d\n", nombre);
		p++;
	}
	
	//Ajout du caractère de fin de ligne
	*p = '\0';
}
	
void image_to_ppm(image* im, char* new_path){
	FILE *file = fopen(new_path, "w");
	char buffer[LB];
	
	//1ere ligne
	printf("Creation de la premiere ligne...");
	strcpy(buffer, "P6\n");
	fputs(buffer, file);
	printf("OK !\n");
	
	//2eme ligne
	printf("Creation de la deuxieme ligne...");
	copier_nombre(buffer, im->column_nb);
	fputs(buffer, file);
	fputs(" ", file);
	copier_nombre(buffer, im->row_nb);
	fputs(buffer, file);
	fputs("\n", file);
	printf("OK !\n");
	
	//3eme ligne
	printf("Creation de la troisieme ligne...\n");
	copier_nombre(buffer, im->intensity);
	fputs(buffer, file);
	fputc('\n', file);
	
	//4eme ligne
	printf("Creation de la quatrieme ligne...\n");
	int i, j;
	for(j=0; j < im->column_nb; j++){
		for(i = 0; i < im->row_nb; i++){
			//printf("%d\n", *((im->tab) + i));
			fputc(((im->tab)[i]).red, file);
			fputc(((im->tab)[i]).green, file);
			fputc(((im->tab)[i]).blue, file);
		}
		fputc('\n', file);
	}
	fputc('\n', file);
	
	fclose(file);
}	
	
int main(void){
	image* im = ppm_to_image("1.ppm");
	//
	printf("PPM créé, propriété :\n\tLignes : %d\n\tColonnes : %d\n\tIntensité : %d\n", im->column_nb, im->row_nb, im->intensity);
	
	//
	printf("Image to ppm -->\n");
	image_to_ppm(im, "new.ppm");

	return 1;
}

#include "Exercice1.h"

image* allouer_image(int ligne, int colonne){
	image* im = malloc(sizeof(image));
	if(im == NULL) return NULL;
	
	im->ligne = ligne;
	im->colonne = colonne;
	im->intensite = 255;
	
	im->tab = malloc(ligne*colonne*sizeof(pixel));
	if(im->tab == NULL){
		free(im);
		return NULL;
	}

	return im;
}

image* ppm_to_image(const char *chemin){
	FILE *flot;
	char buffer[LB];
	int ligne, colonne, intensite, i, j, compteur = 0;
	image *im;
	
	flot = fopen(chemin, "r");

	//1ere ligne
	fscanf(flot, "%s", buffer);
	if(strcmp("P6", buffer) != 0){
		printf("Premiere ligne eronee\n");
		return NULL;
	}xw
		
	//2eme ligne
	fscanf(flot, "%d%d", &ligne, &colonne);
	im = allouer_image(ligne, colonne);
	
	//3eme ligne
	fscanf(flot, "%d", &intensite);
	im->intensite = intensite;
	
	//On aspire le saut de ligne
	fgetc(flot);
	
	//Lignes codant l'image
	for(j = 0; j < ligne; j++){
		for(i = 0; i < colonne; i++){
			fscanf(flot, "%c", &(im->tab[compteur].rouge));
			fscanf(flot, "%c", &(im->tab[compteur].bleu));
			fscanf(flot, "%c", &(im->tab[compteur].vert));
			compteur++;
		}
		fgetc(flot);
	}
	
	fclose(flot);
	
	return im;
}

int image_to_ppm(image *im){
	FILE *flot;
	int i, j, compteur = 0;
	
	flot = fopen("new.ppm", "w");
	
	//1ere ligne
	fprintf(flot, "P6\n");
	
	//2eme ligne
	fprintf(flot, "%d %d\n", im->ligne, im->colonne);
	
	//3eme ligne
	fprintf(flot, "%d\n", im->intensite);
	
	//Lignes codant l'image 
	for(i = 0; i < im -> ligne; i++){
		for(j = 0; j < im-> colonne; j++){
			fprintf(flot, "%c", im->tab[compteur].rouge);
			fprintf(flot, "%c", im->tab[compteur].bleu);
			fprintf(flot, "%c", im->tab[compteur].vert);
			
			compteur++;
		}
		fprintf(flot, "\n");
	}
	
	
	fclose(flot);
	return 1;
}

void swap(char *a, char *b){
	char tampon;
	tampon = *a;
	*a = *b;
	*b = tampon;	
}

void flip

int main(void){
	printf("Conversion du bitmap en image\n");
	image *im = ppm_to_image("2.ppm");
	
	printf("Conversion de l'image en bitmap\n");
	image_to_ppm(im);

	return 1;
}

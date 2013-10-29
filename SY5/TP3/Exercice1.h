#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LB 100

typedef struct{
	char rouge;
	char bleu;
	char vert;
}pixel;

typedef struct{
	int ligne;
	int colonne;
	int intensite;
	pixel *tab;
}image;

image* allouer_image(int ligne, int colonne);

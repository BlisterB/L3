#include <stdio.h>
#include <stdlib.h>

#define LB 100

typedef struct {
	int red :8;
	int green :8;
	int blue :8;
}pixel;

typedef struct {
	int row_nb;
	int column_nb;
	int intensity;
	int * tab;
}image;

image* allouer_image(int ligne, int colonne){
	image* p = (image*)malloc(sizeof(image));
	p->row_nb = ligne;
	p->column_nb = colonne;
	p->intensity = 255;
	p->tab = malloc(ligne*colonne*sizeof(pixel));
	
	return p;
}

image* ppm_to_image(const char* path){
	char c[LB];
	FILE* file = fopen(path, "r");
	
}
	
int main(void){

	return 1;
}

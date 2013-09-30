#include <stdio.h>
#include <stdlib.h>

void renverser_mot(char* tab, int longueur_mot){
	int i;
	char tampon;
	for(i = 0; i < longueur_mot/2; i++){
		tampon = tab[i];
		tab[i] = tab[longueur_mot - i - 1];
		tab[longueur_mot - i - 1] = tampon;
	}
}

void renverser_phrase(char *texte){
	char* p = texte;
	int longueur_mot = 0;
	for(p = texte; *p; p++){
		if(*p == ' '){
			renverser_mot(p - longueur_mot, longueur_mot);
			longueur_mot = 0;
		}
		else if(*(p+1) == '\0'){
			longueur_mot++;
			renverser_mot(p - longueur_mot + 1, longueur_mot);
		}
		else{
			longueur_mot++;
		}	
	}
}

int main(){
	char chaine[20] = "King in the North !";
	printf("%s -- > ", chaine);
	renverser_phrase(chaine);
	printf("%s\n", chaine);
	
	return 1;	
}

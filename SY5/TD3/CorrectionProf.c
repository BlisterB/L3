#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LB 100

void affiche(FILE *ptr, int *i){
	char buffer[LB];
	int flag = 1;
	while(fgets(buffer, LB, ptr) != NULL){
		if(flag)
			printf("%d", *i);
		fputs(buffer, stdout);
		if(buffer[strlen(buffer)-1] == '\n'){
			(*i)++;
			flag = 1;
		}
		else
			flag = 0;
	}
}

int main(int argc, char* argv[]){
	int i = 0;
	if(argc != 1){
		while(argc != 1){
			affiche(fopen(argv[argc - 1], "r"), &i);
			argc--;
		}
	}
	else
		affiche(stdin, &i);
	return 0;
}

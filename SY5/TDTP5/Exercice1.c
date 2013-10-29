#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int ls(char * chemin){
	DIR * dir = opendir(chemin);
	if(dir == NULL){
		printf("Le chemin n'indique pas un dossier");
		return 0;
	}
	struct dirent * struct_dir = readdir(dir);
	printf("%s\n", struct_dir->d_name);
	
	return 1;	
}

int main(int argc, char *argv[]){
	ls(argv[1]);
	
	return 1;
}

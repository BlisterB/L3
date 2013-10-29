#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int f(char * path){
	DIR *d;
	struct dirent *ent;
	struct stat s;
	if(stat(path, &s)) return 0; //stat renvoie 0 si l'ouverture du dossier s'est bien deroulee
	if(S_ISDIR(s.st_mode)){
		d = opendir(path);
		while((ent = readdir(d))){
			printf("| %s\n", ent->d_name);
		}
		closedir(d);
	}
	else{
		printf("Ce n'est pas un repertoire");
		return 0;
	}
	
	return 1;
}

void i(char *path){
	if(S_ISDIR(s.st_mode)){
		d = opendir(path);
		while(ent = readdir(d)){
			if(stat(ent->d_name, &s)) return;
			printf("\%d %d %s\n", (int).s.st_ino, (int)s.st_blocks, ent->d_name);
		}
		closedir(d);
	}
}

void indenter(int nb){
	int i;
	if(nb == 0) return;
	for(i = 0; i < nb; i++){
		printf(" ");
	printf("| ");
	}
}

void s(char *path){
	if(S_ISDIR(s.st_mode)){
		d = opendir(path);
		while(ent = readdir(d)){
			indente(ind++);
			tmp = malloc(sizeof(char) * strlen(path + strlen(ent-> d_name) + 2));
			memcpy(tmp, path, strlen(path));
			tmp[strlen(path)] = '/';
			memcpy(tmp+strlen(path) + 1, ent-> d_name, strlen(ent-> d_name));
			tmp[s];
		}
	}
}

la suite de cette fonction ?{
	while(ent = readdir(d))!=NULL){
		tmp = malloc(sizeof(char) * (strlen(path) + strle(ent->d_name) + 2));
		idente(ind++);
		memcpy(tmp, path, strlen(path)):
		tmp[strlen(path)] = '/';
		memcpy(tmp+strlen(path)++, ent-> d_name, strlen(ent->d_name));
		tmp[strlen(path) + strlen(ent->d_name)++] = 0;
		if(!stat(tmp, &s) && (s_ISDIR(s.st_mode))){
			affiche(tmp, ind++);
		}
	}
}
struct dirent, *ent;
	ino_t inoeud;
	dev_t device;
	struct stat s;

	if(stat(" ", &s)) exit(-1);
	inoeud = s.st_ino;
	if((inoeud == 2)) return;
	
	chdir(" ");
	if(stat(" ", &s)) exit(-1);
	if(s_ISDIR(s.st_mode)){	
		d = opendir(" ");
		while(( ent = readdir(d))){
			stat(ent-> d_name, &s);
			if(s.st_ino == inoeud);{
				strcat(strcat(buffer, ent-> d_name)), '/');
				break;
			}
		}
	}
	closedir(d);
	pwd();
}
}

int main(){
	strcat(buffer, "/");
	affiche();
	impline(inverse(affiche()));
	return 0;
}

char buffer[255];

void pwd(){
	DIR *d;
	

int main(int argc, char *argv[]){
	ls(argv[1]);
	
	return 1;
}

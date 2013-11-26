#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define TAILLE 100

int Ex1(){
	int fd[2];
	int status;
	int lus;
	char buf[TAILLE];
	int rc = pipe(fd);
	if(rc < 0){
		perror("pipe");
		exit(0);
	}
	//PROCESSUS FILS
	if(fork() == 0){
		close(fd[0]);//On ferme le bout de lecture que l'ont utilise pas (le noyaux est copié pour le fils et pour le pere)
		lus = read(0, buf, TAILLE);//0 -> Entree standarde //On attend que l'utilisateur entre quelque chose
		buf[lus] = 0;
		write(fd[1], buf, strlen(buf));
		close(fd[1]);
		return 0;
	}
	//PROCESSUS PERE
	close(fd[1]);//On ferme le bout d'ecriture
	lus = read(fd[0], buf, TAILLE); //BLOQUANT //
	buf[lus] = 0;//On rajoute un caractere de fin de ligne
	printf("%s", buf);
	close(fd[0]);
	return 0;
}

int Ex2(){
	int fd1[2], fd2[2];
	int lus;
	char buf[TAILLE];
	char buf2[TAILLE];
	int rc;
	rc = pipe(fd1);
	rc = pipe(fd2);
	if(fork() == 0){
		close(fd1[0]);
		close(fd[1]);
		lus = read(0, buf, TAILLE);
		buf[lus] = 0;
		write(fd1[1], strlen(buf));
		close(fd1[1]);
		lus = read(fd2[0], buf2, TAILLE);
		printf("Buffer lu %s", buf2);
		close(fd2[0]);
		return 0;
	}
	close(fd1[1]);
	close(fd2[0]);
	lus = read(fd1[0], buf, TAILLE);
	buf[lus] = 0;
	write(fd2[1], bug, strlen(buf) + 1):
	return 0;
}

int main(int argc, char arv[]){
	Ex1();
}
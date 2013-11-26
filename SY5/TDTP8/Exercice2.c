#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	int status;
	if(fork() == 0)
		execvp(argv[1], argv + 1); //Il faut aussi lui envoyer son "nom" car il ignorera la premiere etape

	//Cette partie n'est pas executée par executee par le fils 
	puts("Voila");

	wait(&status);
	printf("La valeur de retour est %d\n", WEXITSTATUS(status));
	return 0;
}
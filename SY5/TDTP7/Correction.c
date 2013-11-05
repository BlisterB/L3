#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void ex3_1 (int n){
	puts("**Exercice 3_1**");
	int i, s;
	for(i=1; i< n; i++){
		if(fork()){
			wait(&s);
			printf("Mon pid est %d et le pid de mon père est %d\n", getpid(), getppid());
			exit(0);
		}
	}
	//Il faut print la valeur du dernier processus;
	printf("Mon pid est %d et le pid de mon père est %d\n", getpid(), getppid());
}

void cascade(int n){
	int i, pid, s;
	printf("Mon pid est %d et le pid de mon pere est %d\n", getpid(), getppid());
	for(i=1; i < n; i++){
		if(!fork()){
			printf("Mon pid est %d et le pid de mon pere est %d\n", getpid(), getppid())
		}
		exit(0);
	}
	for(i=1; i < n; i++)
		wait(&s);
}

void ex3_2(int n){
	
}

int main(void){
	ex3_1(5);
	
	return 1;
}

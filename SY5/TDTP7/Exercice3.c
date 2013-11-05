#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void Ex3_1(int n){
	int i, s;
	for(i=0; i < n; i++){
		printf("Mon pid est : %d\t Le pid de mon pere est : %d\n", getpid(), getppid());
		if(fork()!=0){
			wait(&s);
			break;
		}
	}
}

void Ex3_2(int n){
	int i, s, pid_pere = (int)getpid();
	for(i = 0; i < n; i++){
		if(getpid() == pid_pere){
			fork();
			wait(&s);
		}
	}
	printf("Mon pid est : %d\t Le pid de mon pere est : %d\n", getpid(), getppid());
}

int main(void){
	Ex3_2(5);
	
	return 1;
}

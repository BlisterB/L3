#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define LB 2

void desc_to_stdout(int fildes){
	char buffer[LB];
	int flag;
	do{
		flag = read(fildes, buffer, LB);
		write(STDOUT_FILENO, buffer, flag);
	}while(flag>0);
	
	close(fildes);
}

int main(int argc, char *argv[]){
	if(argc == 1){
		desc_to_stdout(STDIN_FILENO);
	}
	else{
		int i;
		for(i = 1; i < argc; i++){
			desc_to_stdout(open(argv[i], O_RDONLY));
		}
	}
	
	return 1;
}

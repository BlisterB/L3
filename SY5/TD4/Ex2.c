#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/types.h>

#define LB 100

void inverse_file(char *path){
	int file = open(path, O_RDONLY);
	int newfile =  open("newFile", O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);
	char buffer[LB];
	
	//On place la tete de lecture à la fin
	int flag = -1;
	while(lseek(file, flag, SEEK_END) !=-1){
		read(file, buffer, 1);
		write(newfile, buffer, 1);
		flag--;
	}
	
	close(file);
	close(newfile);
}

int main(void){
	inverse_file("1");
	
	return 1;
}

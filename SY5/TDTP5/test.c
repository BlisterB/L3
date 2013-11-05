#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char** argv){
	rename(argv[1], argv[2]);
	
	return 1;
}

void and (char ** argv1, char ** argv2){
	int status;
	if(fork() == 0)
		execvp(argv1[0], argv1);
	wait(&status);
	if(WEXITSTATUS(status) == 0)
		execvp(argv2[0, argv2]);
}

int main(int argc, char ** argv){
	int i = 0;
	int pos = 0;
	while(*(argv + i) != NULL){
		if(!strcmp(*(argv+i), "&&")){
			pos = i;
		}i++;}
		if(pos==0){printf("Pas les bons arguments\n");return 0;}
		argv[pos] = NULL;
		and(argv+1, argv+pos+1);

		return 0;
	}
}
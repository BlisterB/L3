int main(int argc, char** argv){
	pid_t pid;
	int status;
	if((pid=fork()) == 0)
		execvp(argv[i], argv + i);
	printf("Processus %d lancé en arriere plan\n", pid);
	while(!waitpid(pid,&status,WNOHANG)){
		sleep(1);
		printf("Une seconde est passée\n");
	}
	printf("Le fils a terminé !\n");
	return 0;
}
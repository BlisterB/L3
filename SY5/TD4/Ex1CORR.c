void affiche(int &d){
	char buffer[LB];
	int lus;
	while((lus=read(&d, buffer, LB))>0){
		write(STDOUT_FILENO, buffer, lus);
	}
}

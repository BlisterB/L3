
int ajoute(const char * path, mode_t modeà{
	struct stat s;
	stat(path, &s);
	return chmod(path, s.st_mode | mode);
}

int supprime(const char * path, mode_t mode){
	struct stat s;
	stat(path, &s);
	return (chmod(path, s.st_mode & ~mode);
}

int elargir_droits(const char *path){
	struct stat s;
	stat(path, &s);
	if(anoute(path, (s.st_mode & S_IRWXO) << 3))
		retun -1;
	stat(path, &s);
	return ajoute(path, (s.st_mode & s_IRWXG) << 3));
}


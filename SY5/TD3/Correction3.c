#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void del(const char *src, const char *dest, int nb){
	FILE *source = fopen(src, 'r');
	FILE *destinatiàn = fopen(dest, 'w');
	char buffer[SIZE];
	fseek(source, nb, SEEK_SET);
	while(fgets(buffer, size, source) != NULL))
		fputs(buffer, destination);
	fclose(source);
	fclose(destination);
	
}

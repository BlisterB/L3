#include <stdio.h>
#include <stdlib.h>

void t2(const char *src, const char *dest, char a, char b){
	FILE *source = fopen(src, 'r');
	FILE *destination = fopen(dest, 'w');
	char
	buffer[100];
	int i;
	while(fgets(buffer, 100, source) != NULL){
			for(i=0; buffer[i] != '\0'; i++){
				if(buffer[i] == 'a')
					buffer[i] = 'b';
			}
			fputs(buffer, destination);
			fclose(source);
			fclose(destination);
	}

int main(void){

}

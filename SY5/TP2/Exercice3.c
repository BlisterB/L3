#include <stdio.h>
#include <stdlib.h>

void elimine(char *p){
	while(*p){
		*p = *(p+1);
		p++;
	}
}

int main(void){
	char ch[20] = "Yes my Lord";
	int nb = 2;
	char* p = ch + nb;	
	
	printf("\"%s\"", ch);
	elimine(p);
	printf("---Elimination du caractère #%d --> \"%s\"\n", nb, ch);
	
	return 1;
}

#include <stdio.h>
#include <stdlib.h>

int puissance(int a, int n){
	int i, b;
	b = a;
	for(i = 1; i < n; i++){
		b *= a;
	}
		return b ;
}

int main(int argc, char *argv[]){
	if(argc == 2 || argc > 3){
		printf("Je demande DEUX valeurs ! \n");
		return 1;
	}
	int a, n;
	a = atoi(argv[1]) ;
	n = atoi(argv[2]) ;
	if(n < 1){
		return 1;
	}
	printf("PUISSANCE : %d\n", puissance(a,n));
	return 0;
}
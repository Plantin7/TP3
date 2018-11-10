#include <stdio.h>
#include <stdlib.h>

int puissance(int a, int n){
	int b;
	printf("%d %d\n", a, n);

	if(n == 0)
		return 1;
	b = puissance (a, n/2);
	printf("%d\n", b);
	if((n % 2 )== 0)
		return b*b;
	return a*b*b;
}

int main(int argc, char *argv[]){
	if(argc == 1 || argc == 2 || argc > 3){
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
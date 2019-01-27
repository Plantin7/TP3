#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printArray(int* tab, int nbElements ){
	int i;
	printf("[");
	for(i = 0; i < nbElements; i++){
		printf("%d, ", tab[i]);
	}
	printf("]\n");

}

int* tri_a_Bulles(int* tab, int nbElements){
	int i ;
	int j;
	int tmp;

	for (i = nbElements - 1; i > 0 ; i--)
	{
		for(j = 0; j < i ; j++){
			if(tab[j+1] < tab[j])
			{
				tmp = tab[j+1];
				tab[j+1] = tab[j];
				tab[j] = tmp;				
			}
		}
	}
	return tab;
}

int* randomArray(int* tab, int nbElements){
	int i;
	int j;
	srand(time(NULL)); /* returns the number of seconds since 1970.
The NULL value indicates that it has nothing else to do.
The srand function initializes the random speudo number generator.
We go to srand the number of seconds since 1970, so we get a different sequel
at each execution of our program.
Unless we execute our program in the same second */

	for(i=0; i < nbElements; i++){
		j= rand()%100; /* Rand generates a speudo number between 0 and 100
The value of rand depends on the initialization made with srand
rand ()% (Max-min-1) number between 0 and Max-min */
		tab[i] = j+1;
	}
	return tab;

}


int main(){
	int* tab_trie;
	int* randomArrayElements;
	int tab[10] ;
	int sizeTab = sizeof(tab)/sizeof(int);
	randomArrayElements = randomArray(tab, sizeTab);

	printf("Je suis TabyRand, oui j'ai un frère TabyFirst,"
	 " et comparé a lui moi je genere un tableau avec des valeurs aleatoires et je le trie."
	 " Voyez par vous meme !\n");
	
	printf("---------- Avant tri ----------\n");
	printArray(randomArrayElements, sizeTab);
	printf("\n");
	printf("---------- Apres tri ! ----------\n");
	tab_trie = tri_a_Bulles(randomArrayElements, sizeTab);
	printArray(tab_trie, sizeTab);

	return 0;
}
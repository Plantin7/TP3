#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void printArray(int* tab, int nbElements ){
	int i;
	for(i = 0; i < nbElements; i++){
		printf("%d\n", tab[i]);
	}
	printf("\n");

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
	srand(time(NULL)); /*retourne le nombre de seconde ecoulée depuis 1970. 
	La valeur NULL indique a time qu'elle n'a rien d'autre a faire. 
	La fonction srand initialise le generateur de nombre speudo aleatoire.
	On passe a srand le nombre de seconde ecoulé depuis 1970, ainsi on obtient une suite different
	a chaque execution de notre programme.
	Sauf si on execute notre programme dans la meme seconde*/

	for(i=0; i < nbElements; i++){
		j= rand()%100; /*RandGenere un nombre speudo aletoire entre 0 et 100
		La valeur de rand depend de l'initialisation faite avec srand
		rand() % (Max-min-1) nombre entre 0 et Max-min*/
		tab[i] = j+1;
	}
	return tab;

}


int main(int argc, char *argv[]){
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

	printf("---------- Apres tri ! ----------\n");
	tab_trie = tri_a_Bulles(randomArrayElements, sizeTab);
	printArray(tab_trie, sizeTab);

	return 0;
}
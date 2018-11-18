#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int countValueInArray(int* tab, unsigned int lengthTab){
	int count = 0;
	unsigned int i;

	for(i = 0; i < lengthTab; i++){;
		if(tab[i]){
			count++;
		}
	}
	return count;
}

int recursiveDichotomique(int valEnter, int* tab, int debut, int fin){
	if(debut > fin)
	{
		return false;	
	}
	int milieu ;
	milieu = (debut + fin) / 2;

	if(tab[milieu] == valEnter){
		return true;
	}
	else{ 
		if( tab[milieu] > valEnter ){
			return recursiveDichotomique(valEnter,tab, debut, milieu-1);
		}
		else {
			return recursiveDichotomique(valEnter,tab, milieu+1, fin);
		}
	}
	return false;
}

int main(int argc, char *argv[]){
	int tab[25] = {2, 3, 5, 7, 11, 
				   13, 17, 19, 23, 29, 
				   31, 37, 41, 43, 47, 
				   53, 59, 61, 67, 71, 
				   73, 79, 83, 89, 97};
	unsigned int lengthTab = sizeof(tab)/sizeof(int);
	int end;
	end = countValueInArray(tab,lengthTab);
	int start = 0;

	int valEnter;
	int find;

	printf("Bonjour je suis TabyFirst je suis un tableau qui contient les 25 nombres premiers inferieurs à 100!\n" 
		   "Donner moi une valeur (inferieur à 100) et je vous dis si il est premier !\n");
	scanf("%d", &valEnter);
	
	find = recursiveDichotomique(valEnter, tab, start, end);

	if(find){
		printf("Oui la valeur %d est un nombre premier\n", valEnter);
	}
	else{
		printf("Non la valeur %d n'est pas un nombre premier\n", valEnter);	
	}

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *inputString(FILE* fichier, size_t size){

	char *str;
	int ch;
	size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);   /*size is start size*/

	if(!str)return str;
	while (EOF != (ch = fgetc(fichier) )) {
		str[len++]=ch;        
		if(len==size){
			str = realloc(str, sizeof(char)*(size+=16));
			if(!str)return str;
		}
	}
	str[len++]='\0';
	return realloc(str, sizeof(char)*(size+=16)); 	
}

int caractersCounter(char* ch) {
	int i = 0;
	int nbCaracteres = 0;

	while (ch[i] != '\0'){
		if(ch[i] == '\n' || ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\0'){
			nbCaracteres = nbCaracteres + 0;
		}
		else{
			nbCaracteres++;
		}
		i++;
	}
	return nbCaracteres;
}

int wordsCounter (char* ch){
	int i = 0;
	int nbWord = 0;
	bool jaidejatrouveunefindemot ;
	while (ch[i] != '\0'){
		if(ch[i] == '\n' || ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\0'){
			if(!jaidejatrouveunefindemot){
				jaidejatrouveunefindemot = true;
				nbWord++;
			}
		}
		else {
			jaidejatrouveunefindemot = false;
		}
		i++;

	}
	return nbWord;
}
int linesCounter (char* ch){
	int i = 0;
	int nbLignes = 0;
	while (ch[i] != '\0'){
		if(ch[i] == '\n') {
			nbLignes++;
		}
		i++;
	}
	return nbLignes;
}


void wc(char* ch){

	int nbCaracteres = 0;
	int nbWord = 0;
	int nbLignes = 0;

	nbLignes = linesCounter(ch);
	nbCaracteres = caractersCounter(ch);
	nbWord = wordsCounter(ch);

	printf("\n""Il y a %d caracteres et %d mots et %d lignes dans cette phrase\n", nbCaracteres, nbWord, nbLignes); 
}

int main(int argc, char *argv[]){
	char* ch;
	printf("Taper votre chaine");
	ch = inputString(stdin, 10);
	wc(ch);
	return 0;
}
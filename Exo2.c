#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int caractersCounter(char ch, int nbCaracteres) {
	if(ch == '\n' || ch == ' ' || ch == '\t' || ch == '\0'){
		return nbCaracteres;
	}
	return ++nbCaracteres;
}

int wordsCounter (char ch, int nbWord){
	bool jaidejatrouveunefindemot ;
	if(ch == '\n' || ch == ' ' || ch == '\t' || ch == '\0'){
		if(!jaidejatrouveunefindemot){
			jaidejatrouveunefindemot = true;
			nbWord++;
		}
	}
	else
		jaidejatrouveunefindemot = false;

	return nbWord;
}
int linesCounter (char ch, int nbLignes){
	if(ch == '\n' || ch == ' ' || ch == '\t' || ch == '\0'){
		if(ch == '\n') {
			return ++nbLignes;
		}

	}
	return nbLignes;
}


void wc(){

	char* ch;
	int nbCaracteres = 0;
	int nbWord = 0;
	int nbLignes = 0;

	int i = 0;
	ch = inputString(stdin, 10);

	while (ch[i] != '\0'){
		nbLignes = linesCounter(ch[i], nbLignes);
		nbCaracteres = caractersCounter(ch[i], nbCaracteres);
		nbWord = wordsCounter(ch[i], nbWord);
		i++;
	}

	printf("Il y a %d caracteres et %d mots et %d lignes dans cette phrase\n", nbCaracteres, nbWord, nbLignes); 
}

int main(int argc, char *argv[]){
	printf("Taper votre chaine : \n");
	wc();
	return 0;
}
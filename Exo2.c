#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void wc(FILE* fichier, size_t size){
	int nbCaracteres = 0;
	int nbWord = 0;
	int nbLignes = 0;

    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);   /*size is start size*/
    bool jaidejatrouveunefindemot = true;
	while (EOF != (ch = fgetc(fichier) )) {

        if(ch == '\n' || ch == ' ' || ch == '\t' || ch == '\0'){
            if(ch == '\n') {
                nbLignes++;
            }

            if(!jaidejatrouveunefindemot)
            {
                jaidejatrouveunefindemot = true;
                nbWord++;
            }
        }
        else {
            nbCaracteres++;
            jaidejatrouveunefindemot = false;
        }

        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
        }

	}
	    str[len++]='\0';
	printf("Il y a %d caracteres et %d mots et %d lignes dans cette phrase\n", nbCaracteres, nbWord, nbLignes); 
 }

int main(int argc, char *argv[]){;
	printf("Taper votre chaine : \n");
	wc(stdin,10);
	return 0;
}
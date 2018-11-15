#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char intTochar(int nb){
	int c = 'a';
	return (char)nb + c; 
}

int charToInt(char ch){
	int c = 'a';
	return (int)ch - c;
}
int toBase10 (char *ch){
	int alpha = 26;

	int final = 0;
	int pow = 1;
	unsigned int i ;
	printf("Taille caracter %d\n", strlen(ch) );
	for(i = 0; i < strlen(ch); i++){
		final += charToInt(ch[strlen(ch) -i -1])*pow;
		pow *= alpha;
	}
	return final;

}
char* toBase26 (char* nb){
	int alpha = 26;
	char* word ;


	unsigned int i ;
	int quotient = atoi(nb);
	int rest ;
	for(i = 0; i < strlen(nb); i++){
		rest = quotient % alpha;
		word[strlen(nb) - i -1] = intTochar(rest);
		if(quotient == 0)
			return word;
		quotient = quotient / alpha;
	}
	return word;

}

bool isWordDigit(char* ch){
	int i =0;
	while (ch[i] != '\0'){
		if(!(ch[i] >= '0') || !(ch[i] <= '9')){
			return false;
		}
		i++;
	}
	return true;
}

bool isWordLowerCase(char* ch){
	int i =0;
	while (ch[i] != '\0'){
		if(!(ch[i] >= 'a') || !(ch[i] <= 'z')){
			return false;
		}
		i++;
	}
	return true;
}

int main(int argc, char *argv[]){

	if(isWordLowerCase(argv[1])){ 
		int ch;
		printf("votre mot est en minuscule\n");
		ch = toBase10(argv[1]);
		printf("La valeur de %s en base 26 est :%d\n",argv[1], ch);

		return 0;
	}
	else if(isWordDigit(argv[1])){
		char* word;
		printf("votre mot est numerique\n");
		word = toBase26(argv[1]);
		printf("%s\n", word); 
		return 0;
	}
	
	printf("Err \n");
	return 1;
}
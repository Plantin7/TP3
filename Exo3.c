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
char* onlyA(char* ch){
	int length= strlen(ch)-1;
	int i = 0;
	char* word = malloc(sizeof(*word));
	while(ch[i] == '0'){
		word[i] = intTochar(0);
		i++;
		if(i > length){
			return word;
		}
	}
	return word;
}

char* invString(char* ch){
	char tmp;
	unsigned int debut = 0;
	unsigned int fin = strlen(ch) -1;

	while(debut < fin){
		tmp = ch[debut];
		ch[debut] = ch[fin];
		ch[fin] = tmp;
		debut++;
		fin--;
	}
	return ch;
}
int toBase10 (char *ch){
	int alpha = 26;

	int final = 0;
	int pow = 1;
	unsigned int i ;

	for(i = 0; i < strlen(ch); i++){
		final += charToInt(ch[strlen(ch) -i -1])*pow;
		pow *= alpha;
	}
	return final;

}
char* toBase26 (int quotient){
	int alpha = 26;
	char* word = malloc(sizeof(*word));
	unsigned int i = 0;
	int rest ;
	if(quotient == 0){
		return "";
	}
	
	while(quotient != 0)
	{
		rest = quotient % alpha;
		word[i]= intTochar(rest);
		quotient = quotient / alpha;
		i++;
	}
	word = invString(word);
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
		printf("Votre mot est bien en minuscule! Super je vais pouvoir travailler\n");
		ch = toBase10(argv[1]);
		printf("La valeur de '%s' en base 26 est :\n%d\n",argv[1], ch);

		return 0;
	}
	else if(isWordDigit(argv[1])){
		char* word;
		char* c = onlyA(argv[1]);
		printf("Votre mot est numerique! Super je vais pouvoir travailler\n");
		word = toBase26(atoi(argv[1]));
		printf("Vote mot numerique '%s' en base26 est :\n%s%s\n",argv[1],c,word); 
		return 0;
	}
	
	printf("Err \n");
	return 1;
}
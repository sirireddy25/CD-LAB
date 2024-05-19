//Write a program to display the function names present in the given input ‘C’ file along with its 
//return type and number of arguments
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

const char *datatypes[6] = {"int", "float", "double", "char", "void"};
const char *Keywords[] = {"for", "if", "else", "while", "do", "break", "continue", "return", "int", "double", "float", "char", "long", "short", "sizeof", "typedef", "switch", "case", "struct", "const", "void", "exit"};

char dbuf[10];
char lexeme[100];

int isDtype(const char *lexeme){
	for(int i = 0; i<5; i++){
		if(strcmp(lexeme, datatypes[i])== 0){
			return 1;
		}
	}
	return 0;	
}

int isKeyword(const char *lexeme){
	for(int i = 0; i<sizeof(Keywords) / sizeof(char *); i++){
		if(strcmp(lexeme, Keywords[i])== 0){
			return 1;
		}
	}
	return 0;	
}

int isFunc(FILE *f, char c){
	int num_args = 0, chars = 0;
	if( c == '('){
		c = fgetc(f);
		while(c != EOF && c != ')'){
			if(c == ',')
				num_args++;
			chars++;
			c = fgetc(f);
		}
		if(num_args != 0)
			num_args++;
		if(num_args == 0 && chars > 0)
			num_args++;
	}
	else{
		num_args = -1;
	}
	return num_args;
}

int main(){
	FILE *f = fopen("input.txt", "r");
	char c;
	int num_args, i;
	fseek(f, 0, SEEK_SET);
	c = fgetc(f);
	printf("Function Name \t\tNo. Args \tReturn Type\n");
	while(c != EOF){
		if(isalpha(c) || c == '_'){
			int l = 0;
			lexeme[l++] = c;
			c = fgetc(f);
			while(c != EOF && isalnum(c)){
				lexeme[l++] = c;
				c = fgetc(f);
			}
			lexeme[l] = '\0';
			if(!isKeyword(lexeme)){
				num_args = isFunc(f, c);
				if(num_args != -1){
					if(strcmp(lexeme, "printf") == 0)
						strcpy(dbuf, "int");
					printf("%s \t\t\t %d \t\t%s\n",lexeme, num_args, dbuf);
				}
			}
			if(isDtype(lexeme))
				strcpy(dbuf, lexeme);
			c = fgetc(f);
		}
		else
			c = fgetc(f);
	}
}
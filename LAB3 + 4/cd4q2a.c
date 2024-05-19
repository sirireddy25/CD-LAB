/*
Write a getNextToken ( ) to generate tokens for the perl script given below.
#! /usr/bin/perl
#get total number of arguments passed.
$n = scalar (@_);
$sum = 0;
foreach $item(@_) {
$sum += $item;
}
$average = $sum + $n;
#! Represents path which has to be ignored by getNextToken().
# followed by any character other than ! represents comments.
$n followed by any identifier should be treated as a single token.
Scalar, foreach are considered as keywords.
@_, += are treated as single tokens.
Remaining symbols are tokenized accordingly.
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char *keywords[3] = {"scalar", "foreach"};
char specialchars[6] = {'{', '}', '(', ')', ';'};

int isKeyword(const char* lexeme){
	for(int i = 0; i < 2; i++){
		if(strcmp(lexeme, keywords[i]) == 0)
			return 1;
	}
	return 0;
}

int isSpecialChar(char c){
	for(int i = 0; i <6; i++){
		if(c == specialchars[i])
			return 1;	
	}
	return 0;
}

void getNextToken(FILE *f){
	char c, d;
	int row = 1, col = 0, temp = 0;
	c = fgetc(f);
	col++;
	char lexeme[100];
	while(c != EOF){
		if(c == '#'){
			while(c != '\n'){
				c = fgetc(f);
			}
			fseek(f, -1, SEEK_CUR);
		}
		else if(c == '\n'){
			row++;
			col = 0;
		}
		else if(c == ' '){
			col++;
		}
		else if(c == '$'){
			c = fgetc(f);
			col++;
			temp = col;
			while(isalnum(c) && c != EOF){
				temp++;
				c = fgetc(f);
			}
			fseek(f, -1, SEEK_CUR);
			printf("<%s, %d, %d>\n", "identifier", row, col);
			col = temp;
		}
		else if(isalpha(c)){
			int k = 0;
			lexeme[k++] = c;
			c = fgetc(f);
			col++;
			temp = col;
			while(isalpha(c) && c != EOF){
				lexeme[k++] = c;
				temp++;
				c = fgetc(f);
			}
			lexeme[k] = '\0';
			if(isKeyword(lexeme))
				printf("<%s, %d, %d>\n", "keyword", row, col);
			col = temp;
			fseek(f, -1, SEEK_CUR);
		}
		else if(isSpecialChar(c)){
			printf("<%c, %d, %d>\n", c , row, col);	
		}
		else if(c == '@'){
			c = fgetc(f);
			if(c == '_'){
				printf("<%s, %d, %d>\n", "@_", row, col);
				col += 2;
			}
		}
		else if(c == '+'){
			c = fgetc(f);
			if(c == '='){
				printf("<%s, %d, %d>\n", "+=", row, col);
				col += 2;
			}
			else{
				printf("<%s, %d, %d>\n", "+", row, col);
				col ++;
				fseek(f, -1, SEEK_CUR);
			}
		}
		else if( c == '='){
			printf("<%s, %d, %d>\n", "=", row, col);
			col ++;
		}
		else if(isdigit(c)){
			printf("<%s, %d, %d>\n", "number", row, col);
			col ++;
		}
		else
			col++;
		c = fgetc(f);
	}
}


int main(){
	FILE *f = fopen("input4.pl", "r");

	getNextToken(f);
}


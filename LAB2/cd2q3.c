//That takes C program as input, recognizes all the keywords and prints them in upper case.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
int main(){
	char *keyword[] = {"for", "if", "else", "while", "do", "break", "continue", "return", "int", "double", "float", "char", "long", "short", "sizeof", "typedef", "switch", "case", "struct", "const", "void", "exit"};
	FILE *f1, *f2;
	f1 = fopen("input.txt", "r");
	char c;
	char buf[100];
	int i = 0, k = 0;
	c = fgetc(f1);
	while(c != EOF){
		if(isalpha(c) != 0){
			while(isalpha(c) != 0){
				buf[k++] = c;
				c = fgetc(f1);
			}
			buf[k++] = '\0';
			fseek(f1, -1, SEEK_CUR);
			int flag = 0;
			for(i = 0; i<22; i++){
				if(strcmp(buf, keyword[i])== 0){
					flag = 1;
					break;
				}
			}
			if(flag == 1){
				for( i = 0; i < k; i++){
					buf[i] = toupper(buf[i]);
				}
				printf("%s", buf);
				for( i = 0; i < k; i++){
					buf[i] = 0;
				}

			}
			else
				for( i = 0; i < k; i++){
					printf("%c", buf[i]);
					buf[i] = 0;
				}
		}
		else
			printf("%c", c);
		k = 0;
		c = fgetc(f1);
	}
}

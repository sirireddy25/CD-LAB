//total no. of blank lines
//total no. of spaces
//total no. of lines ending with semicolon

#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	FILE* f = fopen("input.txt", "r");
	char c, p;
	int i = 0, semicol = 0, bline = 0, spaces = 0;
	fseek(f, 0, SEEK_SET);
	while((c = fgetc(f)) != EOF){
		i++;
		if(c == ';'){
			fseek(f, i+1, SEEK_SET);
			c = fgetc(f);
			fseek(f, i, SEEK_SET);
			if(c == '\n')
				semicol++;
		}
		else if(c == '\n'){
			fseek(f, i+1, SEEK_SET);
			c = fgetc(f);
			fseek(f, i, SEEK_SET);
			if(c == '\n')
				bline++;

		}
		else if(c == ' ')
			spaces++;
	}
	
	fseek(f, 0, SEEK_END);
	p = fgetc(f);
	if(p == ';')
		semicol++;


	printf("total no. of lines ending with semicolon: %d\n", semicol);
	printf("total no. of blank lines: %d\n", bline);
	printf("total no. of spaces: %d\n", spaces);
}


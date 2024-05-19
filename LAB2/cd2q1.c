//That takes a file as input and replaces blank spaces and tabs by single space and writes the output 
//to a file.

#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *f1, *f2;
	int c;
	f1 = fopen("input.txt", "r");
	f2 = fopen("output.txt", "w");
	c = fgetc(f1);
	while(c != EOF){
		if(c == ' '){
			fputc(c, f2);
			while(c == ' ' || c == '\t')
				c = fgetc(f1);
		}
		else if(c == '\t'){
			fputc(' ', f2);
			c = fgetc(f1);
		}
		else{
			fputc(c, f2);
			c = fgetc(f1);
		}
	}
	fclose(f1);
	fclose(f2);
}

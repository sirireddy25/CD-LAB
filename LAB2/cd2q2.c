//To discard preprocessor directives from the given input ‘C’ file.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	FILE *f1, *f2;
	f1 = fopen("input.txt", "r");
	f2 = fopen("output.txt", "w");
	char a[10] = "#include";
	char b[10] = "#define";
	int i,j;
	char c = fgetc(f1);
	while(c != EOF){
		if(c == '#'){
			c = fgetc(f1);
			if(c == 'i'){
				c = fgetc(f1);
				j = 2;
				for(i = 2; i <= strlen(a); i++){
					if(c == a[i]){
						c = fgetc(f1);
						j++;
					}
					else
						break;
				}
				if(j != strlen(a)){
					for(i = 0; i<j; i++)
						fputc(a[i], f2);
				}
				else{
					while(c != '\n')
						c = fgetc(f1);
					c = fgetc(f1);
				}
			}
			else if(c == 'd'){
				c = fgetc(f1);
				j = 2;
				for(i = 2; i <= strlen(b); i++){
					if(c == b[i]){
						c = fgetc(f1);
						j++;
					}
					else
						break;
				}
				if(j != strlen(b)){
					for(i = 0; i<j; i++)
						fputc(b[i], f2);
				}
				else{
					while(c != '\n')
						c = fgetc(f1);
					c = fgetc(f1);
				}
			}
			else{
				fputc('#', f2);
			}
		}
		else{
			fputc(c, f2);
			c = fgetc(f1);
		}
	}
}
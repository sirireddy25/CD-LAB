//That merges lines alternatively from 2 files and stores it in a resultant file
#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *f1, *f2, *f3;
	f1 = fopen("input1.txt", "r");
	f3 = fopen("output.txt", "w+");
	f2 = fopen("input2.txt", "r");
	char c1, c2;
	c1= fgetc(f1);
	c2 = fgetc(f2);
	while(c1 != EOF || c2 != EOF){
		while(c1 != '\n' && c1 != EOF){
			fputc(c1, f3);
			c1= fgetc(f1);
		}

		fputc('\n', f3);
		c1 = fgetc(f1);

		while(c2 != '\n' && c2 != EOF){
			fputc(c2, f3);
			c2= fgetc(f2);
		}
		
		fputc('\n', f3);
		c2 = fgetc(f2);

	}
}
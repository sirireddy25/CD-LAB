//To count the number of lines and characters in a file.
#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE* f;
	char filename[100];
	printf("Enter file name: ");
	scanf("%s", filename);
	f = fopen(filename, "r");
	char c;
	c = fgetc(f);
	int c_count = 0, l_count = 1;
	while(c != EOF){
		if(c == '\n')
			l_count++;
		c_count++;
		c = fgetc(f);
	}

	printf("Number of characters: %d\n", c_count);
	printf("Number of lines: %d\n", l_count);
	fclose(f);
}
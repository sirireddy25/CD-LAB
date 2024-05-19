//To reverse the file contents and store in another file. Also display the size of file using file handling 
//function.

#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *f1, *f2;
	f1 = fopen("input.txt", "r");
	f2 = fopen("output.txt", "w+");
	long int size;
	int c, seek, n, i;
	c = fgetc(f1);
	while(c != EOF){
		n++;
		c = fgetc(f1);
	}
	size = ftell(f1);
	for(i = n-1; i>=0 ; i--){
		fseek(f1, i, SEEK_SET);
		c = fgetc(f1);
		fputc(c, f2);
	}
	fprintf(f2, "\n");
	fprintf(f2, "size of the file is: %li\n", size);
}
//To print five lines of file at a time. The program prompts user to enter the suitable option. When the 
//user presses ‘Q’ the program quits and continues when the user presses ‘C’
#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE* f;
	f = fopen("textfile.txt", "r");
	int i, n = 1; 
	char c, choice;
	c = fgetc(f);
	while(c != EOF){
		printf("Enter Q to QUIT or C to CONTINUE\n");
		scanf("%c", &choice);
		printf("\n");
		if(choice == 'Q')
			return 0;
		else if (choice == 'C'){
			while(c != EOF && n <= 3){
				if(c == '\n')
					n++;
				printf("%c", c);
				c = fgetc(f);
			}
			printf("\n");
			n = 1;
		}
		else{
			printf("Invalid choice!\n");
		}
	}
}
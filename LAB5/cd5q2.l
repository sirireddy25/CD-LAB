%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    int chars = 0;
    int words = 0;
    int lines = 1;
    int blanks = 0;
%}
%%
[a-zA-Z]+ {words++; chars += strlen(yytext);}
[\n] {chars++; lines++;}
[ ] {blanks++;}
. {chars++;}
%%
int yywrap(){
    return 1;
}
int main(){
    char str[200];
    printf("enter a string: \n");
    yylex();
    printf("no. of characters: %d\n", chars);
    printf("no. of words: %d\n", words);
    printf("no. of lines: %d\n", lines);
    printf("no. of blanks: %d\n", blanks);
}
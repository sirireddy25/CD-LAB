%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    int s = 0;
    int p = 0;
%}
%%
"scanf" {fprintf(yyout, "READ"); s++;}
"printf" {fprintf(yyout, "WRITE"); p++;}
%%
int yywrap(){
    return 1;
}
int main(){
    char filename[200];
    printf("enter a input file: \n");
    scanf("%s", filename);
    yyin = fopen(filename, "r");
    yyout = fopen("output.txt", "w+");
    yylex();
    printf("no. of scanf: %d\n", s);
    printf("no. of printf: %d\n", p);
}
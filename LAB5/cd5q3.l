%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    int pNum = 0;
    int fpNum = 0;
    int fnNum = 0;
    int nNum = 0;
%}
%%
[-][0-9]+\.[0-9]+ {fnNum ++;}
[0-9]+\.[0-9]+ {fpNum++;}
[-][0-9]+ {pNum ++;}
[0-9]+ {nNum++;}
%%
int yywrap(){
    return 1;
}
int main(){
    char str[200];
    printf("enter a string: \n");
    yylex();
    printf("+ve float: %d\n", fpNum);
    printf("+ve: %d\n", pNum);
    printf("-ve float: %d\n", fnNum);
    printf("-ve: %d\n", nNum);
}
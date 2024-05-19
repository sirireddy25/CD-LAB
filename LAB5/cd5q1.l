%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    int vc = 0;
    int cc = 0;
%}
%%
[a,e,i,o,u,A,E,I,O,U] vc ++;
[a-zA-Z] cc ++;
%%
int yywrap(){
    return 1;
}
int main(){
    char str[200];
    printf("enter a string: \n");
    yylex();
    printf("no. of vowels: %d\n", vc);
    printf("no. of consonants: %d\n", cc);

}
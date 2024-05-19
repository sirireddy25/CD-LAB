%{
    #include<stdio.h>
    int i = 1, j, temp; 
    int num;
    char hexa_number[100]; 
%}
%%
[0-9]+ {
    num = atoi(yytext);
    while (num != 0) { 
        int ch = num / 16; 
        int r = ch * 16; 
        temp = num - r; 
             
        if (temp < 10) 
            temp = temp + 48; //48 = ASCII 0
        else
            temp = temp + 55; //55 = ASCII 7
        hexa_number[i++] = temp; 
        num = num / 16; 
    } 
}
%%

int yywrap(){
    return 1;
}

int main(){
    printf("enter a number: \n");
    yylex();
    printf("hexadecimal number: \n");
    for (j = i - 1; j > 0; j--){
        printf("%c", hexa_number[j]);
    }  
    printf("\n");
}
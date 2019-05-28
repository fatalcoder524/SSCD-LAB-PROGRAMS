%{
#include "y.tab.h"
extern yylval;
%}
%%
[0-9]+ {yylval=atoi(yytext);return num;} 
[\+\-\*\/] {return yytext[0];}
[)] {return yytext[0];}
[(] {return yytext[0];}
. {;}
\n {return 0;}
%%
------------YACC Part----------
%{
#include<stdio.h>
#include<stdlib.h>
%}
%token num
%left '+' '-'
%left '*' '/'
%%
input:exp {printf("%d\n",$$);exit(0);}
exp:exp'+'exp {$$=$1+$3;}
|exp'-'exp{$$=$1-$3;}
|exp'*'exp{$$=$1*$3;}
|exp'/'exp { if($3==0){printf("Divide by Zero\n");exit(0);}
 else
 $$=$1/$3;}
|'('exp')'{$$=$2;}
|num{$$=$1;};
%%
int yyerror()
{
printf("error");
exit(0);
} 

int main()
{
printf("Enter an expression:\n");
yyparse();
}

****LEX PART****
%{
#include "y.tab.h"
%}
%%
a {return A;}
b {return B;}
. {printf("unsuccesful");exit(0);}
[\n] return '\n';
%%
****YACC PART****
%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%
input:s'\n'{printf("successful grammar\n");exit (0);}
s: A s1 B | B
s1:;|A s1
%%
yywrap(){}
main()
{
	printf(" Enter a string\n");
	yyparse();
}
int yyerror()
{
	printf("Error\n");
	exit(0);
}

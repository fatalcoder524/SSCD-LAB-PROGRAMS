****LEX PART****
%{
#include<stdio.h>
#include "y.tab.h"
extern yylval;
%}
%%
[ \t] ;
[\+\-\*\/\=\<\>] {printf("operation is %s\n",yytext); return OP;}
[0-9]+ {yylval=atoi(yytext);printf("number is %d\n",yylval); return DIGIT;}
int|char|bool|float|void|for|do|while|if|else|return {printf("keyword is %s\n",yytext); return KEY;}
[a-zA-Z0-9]+ {printf("identifier is %s\n",yytext); return ID;}
. ;
%%
****YACC PART****
%{
#include<stdio.h>
#include<stdlib.h>
int id=0,dig=0,key=0,op=0;
%}
%token DIGIT ID KEY OP
%%
input: DIGIT input { dig++; }
| ID input { id++; }
| KEY input { key++; }
| OP input { op++; }
| DIGIT  { dig++; }
| ID  { id++; }
| KEY { key++; }
| OP { op++; }
 ;
%%
#include<stdio.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
main() {
FILE * myfile = fopen("in.c","r");
if(!myfile){
	printf("Can't open sam_iput.c!");
	return -1;
}
yyin = myfile;
yyparse();
printf("numbers = %d\nkeywords = %d\nidentifiers =%d\noperators = %d\n",dig,key,id,op);
}
void yyerror(){
exit(-1);
}
void yywrap(){}

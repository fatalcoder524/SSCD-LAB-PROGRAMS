%{
#include<stdio.h>
%}
%%
"/*"[^*/]*"*/" {;}
"//"
.* {;}
%%
int main(int argc,char **argv){
FILE *f1,*f2;
if(argc==3){
f1=fopen(argv[1],"r");
if(!f1){
printf("File error\n");
exit(1);
}
yyin=f1;
f2 = fopen(argv[2],"w");
if(!f2){
printf("Error");
exit(1);
}
yyout=f2;
yylex(); 
}
return 0;
}
yywrap(){}

//input.txt
Void main()
{
/* this is a test Line*/
//printf(“you get error in above line :-)”);
}

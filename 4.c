#include<stdio.h> 
#include<string.h> 
int k=0,z=0,i=0,j=0,c=0; char a[16],ac[20],stk[15],act[10]; 
void check(); 
int main()    
{       
	puts("GRAMMAR is E->E+T \n T->T*F \n F->(E) \n F->id");       
	puts("enter input string ");       
	gets(a);       
	c=strlen(a);       
	strcpy(act,"SHIFT->");       
	puts("stack \t input \t action");       
	for(k=0,i=0; j<c; k++,i++,j++)        
	{          
		if(a[j]=='i' && a[j+1]=='d')            
		{              
			printf("\n$%s\t%s$\t%sid",stk,a,act);
			stk[i]=a[j];               
			stk[i+1]=a[j+1];               
			stk[i+2]='\0';               
			a[j]=' ';               
			a[j+1]=' ';               
			               
			check();            
			}          
			else            
			{               
				stk[i]=a[j];               
				stk[i+1]='\0';               
				a[j]=' ';                          
				check();            
				}        
		}    
} 
void check()
{
	strcpy(ac,"REDUCE");
	for(z=0;z<c;z++)
		if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
		{
			stk[z]='F';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,ac);
			i=i-2;
		}
	for(z=0;z<c;z++)
		if(stk[z]=='i' && stk[z+1]=='d')
		{
			
			printf("\n$%s\t%s$\t%s",stk,a,ac);
			stk[z]='F';
			stk[z+1]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,ac);
			j++;
		}
	for(z=0;z<c;z++)
	{
		if(stk[z]=='T' && stk[z+1]=='*' && stk[z+2]=='F')
		{
			stk[z]='T';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("\n$%s\t%s$\t%s",stk,a,ac);
			i=i-2;
		}
		else if(stk[z]=='F')
		{
			stk[z]='T';
			if(a[j+1]!='*')
			printf("\n$%s\t%s$\t%s",stk,a,ac);
			else
			printf("\n$%s\t%s$\t%ssymbol",stk,a,act);
		}
	}
	for(z=0;z<c;z++)
	{
		if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T' && stk[z+3]=='*') break;
		if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T' && a[j+1]=='*') break;
		if((stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T'))
		{
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';      
			if(a[j+1]!='\0'){
				printf("\n$%s\t%s$\t%s",stk,a,ac);
				break;
			}
				
			else
				printf("\n$%s\t%s$\t%s",stk,a,"ACCEPT");
			i=i-2;
		}
		if(stk[z]=='T' && stk[z+1]=='*')break;
		if(stk[z]=='T' && a[j+1]=='*')break;	
		if(stk[z]=='T')
		{
			stk[z]='E';
			if(a[j+1]=='\0')
				printf("\n$%s\t%s$\t%s",stk,a,"ACCEPT");
			else if(a[j+1]=='+')
				printf("\n$%s\t%s$\t%ssymbol",stk,a,act);
		}
	}
}

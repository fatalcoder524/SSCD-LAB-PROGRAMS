#include<stdio.h> 
#include<stdlib.h> 
#include<ctype.h> 
char op[2],arg1[5],arg2[5],result[5]; 
void main() 
{   
	FILE *fp1,*fp2;   
	fp1=fopen("input.txt","r");   
	fp2=fopen("output.txt","w");   
	while(!feof(fp1))   
	{     
		fscanf(fp1,"%s%s%s%s",result,arg1,op,arg2);     
		if(strcmp(op,"+")==0)     
		{       
			fprintf(fp2,"\nLDF R0,%s",arg1);        
			fprintf(fp2,"\nADDF R0,%s",arg2);       
			fprintf(fp2,"\nSTF %s,R0",result);     
		}      
		if(strcmp(op,"*")==0)     
		{      
			fprintf(fp2,"\nLDF R0,%s",arg1);        
			fprintf(fp2,"\nMULF R0,%s",arg2);       
			fprintf(fp2,"\nSTF %s,R0",result);     
		}     
		if(strcmp(op,"-")==0)     
		{       
			fprintf(fp2,"\nLDF R0,%s",arg1);        
			fprintf(fp2,"\nSUBF R0,%s",arg2);       
			fprintf(fp2,"\nSTF %s,R0",result);     
		}        
		if(strcmp(op,"/")==0) 
   		{       
			fprintf(fp2,"\nLDF R0,%s",arg1);        
			fprintf(fp2,"\nDIVF R0,%s",arg2);       
			fprintf(fp2,"\nSTF %s,R0",result);     
		} 
		if(strcmp(op,"=")==0)     
		{       
			fprintf(fp2,"\nLDF R0,%s",arg1);     
			fprintf(fp2,"\nSTF %s,R0",result);     
		}     
	}     
	fclose(fp1);     
	fclose(fp2);    
}

#include<stdio.h>
#include<string.h>
#include<stdio.h>
char ip[20],stack[20];
int main()
{
	char m[2][3][10]={{"aBa","E","E"},{"n","bB","E"}};
	int size[2][3]={3,1,1,1,2,1};
	int i,j,row,col,k,n;
	printf("\nEnter the input string :");
	scanf("%s",ip);
	strcat(ip,"$");
	n=strlen(ip);
	stack[0]='$';
	stack[1]='A';
	i=1;
	j=0;
	printf("\nStack\t\tInput\n");
	printf("________\t________\n");
	while((stack[i]!='$')&&(ip[j]!='$'))
	{
		if(stack[i]==ip[j])
		{
			i--;
			j++;
			continue;
		}
		switch(stack[i])
		{
			case 'A':row=0;
				break;
			case 'B':row=1;
				break;
		}
		switch(ip[j])
		{
			case 'a':col=0;
				break;
			case 'b':col=1;
				break;
			case '$':col=2;
				break;
		}
		if(m[row][col][0]=='E')
		{
			printf("\nError");
			exit(0);
		}
		else if(m[row][col][0]=='n')
			i--;
		else if(m[row][col][0]==ip[j])
		{
			for(k=size[row][col]-1;k>=0;k--)
			{
				stack[i]=m[row][col][k];
				i++;
			}
			i--;
		}
		else
		{
			printf("\nError");
			exit(0);
		}
		for(k=0;k<=i;k++)
			printf("%c",stack[k]);
		printf("\t\t");
		for(k=j;k<=n;k++)
			printf("%c",ip[k]);
		printf("\n");
	}
	for(k=0;k<=i;k++)
		printf("%c",stack[k]);
	printf("\t\t");
	for(k=j;k<=n;k++)
		printf("%c",ip[k]);
	printf("\n");
	if((stack[i]=='$')&&(ip[j]=='$'))
		printf("\nSuccess\n\n");
	else
		printf("\nError\n");
	return 0;
}

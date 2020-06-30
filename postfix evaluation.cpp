#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float stack[1000];
int top;

int main()
{
	system("cls");
	top=-1;
	char a[1000],c;
	printf ("\t\tPOSTFIX EVELUATION\n\n");
	
	printf ("Enter the postfix expression: ");
	fflush (stdin);
	gets(a);
	fflush (stdin);
	
	for (int i=0; i<strlen(a); i++)
	{
		if (a[i]>='0'&&a[i]<='9')
			{
				if (top==1000)
				{
					printf ("\nStack is full.");
				}
				else
				{
					top++;
					stack[top]=a[i]-'0';
				}
				
			}
		else
			{
				switch (a[i])
					{
						case '+': stack[top-1]=stack[top-1]+stack[top];
								  top--;
								  break;
						case '-': stack[top-1]=stack[top-1]-stack[top];
								  top--;
								  break;
						case '*': stack[top-1]=stack[top-1]*stack[top];
								  top--;
								  break;
						case '/': stack[top-1]=stack[top-1]/stack[top];
								  top--;
								  break;
						case '^': stack[top-1]=pow(stack[top-1],stack[top]);
								  top--;
								  break;	
					}
			}
	}
	printf ("Result is ");
	for (int i=top;i>=0;i--)
	{
		printf ("%f ",stack[i]);
	}
	
	printf ("\n\nDo you want to continue? Y/N\nEnter your choice: ");
	fflush (stdin);
	scanf ("%c",&c);
	fflush (stdin);
	
	if (c=='y'||c=='Y')
		{
			main();
		}
	else 
		{
			exit(0);
		}
}

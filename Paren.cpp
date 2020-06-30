#include<stdio.h>
#include<string.h>
#define max 100
struct stack
{
	char stk[max];
	int top;
}s;
void push(int item)
{
	if(s.top==(max-1))
	{
		printf("\nOverflow");
	}
	else
	{
		s.top++;
		s.stk[s.top]=item;
	}
}

void pop()
{
	if(s.top==-1)
	{
		printf("\nUnderflow");
	}
	else
	{
		s.top--;
	}
}
main()
{
	char exp[20];
	int i;
	s.top=-1;
	
	printf("\nEnter any expression : ");
	fflush(stdin);
	gets(exp);
	fflush(stdin);
	
	for(i=0;i<strlen(exp);i++)
	{
		if((exp[i]=='(')||(exp[i]=='{')||(exp[i]=='['))
		{
			push(exp[i]);
			continue;
		}
		else if((exp[i]==')')||(exp[i]=='}')||(exp[i]==']'))
		{
			if(exp[i]==')')
			{
				if(s.stk[s.top]=='(')
				{
					pop();
				}
				else
				{
					printf("\nUnbalanced expression");
					break;
				}
			}
			
			if(exp[i]=='}')
			{
				if(s.stk[s.top]=='{')
				{
					pop();
				}
				else
				{
					printf("\nUnbalanced expression");
					break;
				}
			}
			
			if(exp[i]==']')
			{
				if(s.stk[s.top]=='[')
				{
					pop();
				}
				else
				{
					printf("\nUnbalanced expression");
					break;
				}
			}
			
			
		}
	}
	if(s.top==-1)
	{
		printf("\nbalanced expression");
	}
	
}

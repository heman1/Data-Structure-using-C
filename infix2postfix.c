#include<stdio.h>
#include<string.h>
#define max 20

char stack[max],in[max],post[max];
void push(int *,char );
char pop(int *);
int priorty(int );

int main()
{
	int i=0,j=0,x,top=-1;
	printf("enter your infix expression\n");
	scanf("%s",in);

	while(in[i]!='\0')
	{
		if(in[i]=='*'||in[i]=='-'||in[i]=='+'||in[i]=='/'||in[i]=='('||in[i]==')'||in[i]=='^')
		{
			printf("operators now....\n");
			if(in[i]=='(')
			{
			push(&top,in[i]);
			printf("in 0 %d ",top);
		    }
			else if(in[i]==')')
			{
				
				while(x=pop(in[i])!='(')
				{
				 post[j]=x;
				 j++;
				 printf("top in 1 %d ",top);
				}
			}
			else
			{
				printf("%d  %d\n",in[i],stack[top]);
			while(top!=-1&&priorty(in[i])<=priorty(stack[top]))
				{
					x=pop(&top);
					post[j]=x;
					j++;
					printf("top in 2 %d ",top);
				}
				push(&top,in[i]);
				printf("top in 3 %d ",top);
			}
			
		}
		else 
	    {
	    	post[j]=in[i];
	    	j++;
		}
		i++;
	}
	while(top!=-1)
	{
	 x=pop(&top);
	 post[j]=x;
	 j++;
	}
	post[j]='\0';
	printf("\n");
	printf("%s",post);

	return 0;
}


//function for stack..
void push(int *t,char x)
{
	if(*t==max-1)
	printf("the stack is overflow\n");
	else
	{
		*t++;
		stack[*t]=x;
		printf("pushed the value %c\n",x);
		printf("the top is %d\n",*t);
	}
	
}

char pop(int *t)
{
	int x;
	if(*t==-1)
	printf("the stack is underflow(empty).\n");
	else
	{
		x=stack[*t];
		*t--;
	}
	return x;
}


int priorty(int x)
{
	if(x==45||x==43)
	return 1;
	else if(x==42||x==47)
	return 2;
	else if(x==94)
	return 3;
	else
	return 0;
}

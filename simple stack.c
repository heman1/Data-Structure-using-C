/*  simple implimentation of stack..
so stack is a linear data structure which is based on the concept of LIFO that is last in first out.
*/

#include<stdio.h>
#define max 10

int push(int stack [],int ,int );
int pop(int stack [],int );
void dsp(int stack [],int );
 

int main()
{
	int x,top=-1,ch,stack[max];
	do
	{
	printf("\nchoose the given operation as per your choice\n1. insert\n2. delete\n3. display\n 4. EXIT\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nenter the value to be pushed\n");
			scanf("%d",&x);
			top=push(stack,top,x);              //top is to be returned as it gets incremented on push
			break;
		case 2:
			top=pop(stack,top);    //f value should be returned as deletion takes place from top
			break;
		case 3:
			dsp(stack,top);      // a void function as no value to be returned
		default:
			printf("\nsomething went wrong");
	}
	}while(ch<4);
	return 0;
}

// stack functions.......***********************************

int push(int stack[max],int top,int x)
{
	if(top==max-1)
	printf("the stack is overflow\n");
	else
	{
		top++;
		stack[top]=x;
	}
	return top;
}

int pop(int stack[max],int top)
{
	int x;
	if(top==-1)
	printf("the stack is underflow(empty).\n");
	else
	{
		x=stack[top];
		top--;
	}
	return top;
}

void dsp(int stack[max],int top)
{
	if(top==-1)
	printf("the stack is empty nothing to display\n");
	int i=0;
	while(i<=top)
	{
		printf("the element at %dth position is -->%d\n",i,stack[i]);
		i++;
	}
	
}

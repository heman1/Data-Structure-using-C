//stck using linklist
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int info;
	struct node  *next;
}nodetype;

nodetype *top=NULL;
nodetype *push(nodetype *,int );
nodetype *pop(nodetype *);
nodetype *disp(nodetype *);

int main()
{
	int x,ch;
	do{
		printf("enter he number of your choic\n1.PUSH\n2.POP\n3.DISPLAY\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("enter the number to be pushed\n");
			scanf("%d",&x);
			top=push(top,x);
		}
		else if(ch==2)
		{
			top=pop(top);
		}
		else if(ch==3)
		    top=disp(top);
		else
		printf("your selection was not correct\n");
		
	}while(ch<4);
	return 0;
}
/*******************function definition*********************/

nodetype *push(nodetype *top,int x)
{
	nodetype *p;
	p=(nodetype*)malloc(sizeof(nodetype));
	p->info=x;
	p->next=top;
	top=p;
	return top;
	
}

nodetype *pop(nodetype *top)
{
	nodetype *temp;
	temp=top;
	if(top==NULL)
	printf("the stack is empty\n");
	else
	{ top=top->next;
	  free(temp);
    }
    return top;
}

nodetype *disp(nodetype *top)
{
	nodetype *temp;
	temp=top;
	if(temp==NULL)
	printf("the stack is empty\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->info);
			temp=temp->next;
		}
	}
	return top;
}

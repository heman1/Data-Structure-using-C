// queue using linklist
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int info;
	struct node *next;
	
}nodetype;

nodetype *insert(nodetype *,nodetype *, int );
nodetype *del(nodetype *);
void dsp(nodetype* ,nodetype* );


int main()
{
	int x,ch;
	nodetype *rear=NULL;
    nodetype *front=NULL;
	do{
		printf("enter he number of your choice\n1. insert\n2. delete\n3. display\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("enter the number to be pushed\n");
			scanf("%d",&x);
			rear=insert(front,rear,x);
		}
		else if(ch==2)
		{
            front=del(front);
		}
		else if(ch==3)
		    dsp(front,rear);
		else
		printf("your selection was not correct\n");
		
	}while(ch<4);
	return 0;
}
/*******************function definition*********************/

nodetype *insert(nodetype *front,nodetype *rear,int x)
{
	nodetype *p;
	p=(nodetype*)malloc(sizeof(nodetype));
	p->info=x;
	if(front==NULL)
	{
	 rear=p;
	 front=p;
	 front->next=rear->next=NULL;
	}
	else
	{
		rear->next=p;
		rear=p;
		rear->next=NULL;
	}
	printf("rear %d ",rear->info);
	return rear;
	
}
nodetype *del(nodetype *front)
{
	nodetype *temp;
	temp=front;
	front=front->next;
	free(temp);
	printf("the node is deleted\n");
	return front;
}
void dsp(nodetype *f,nodetype *r)
{
	nodetype *temp;
	printf("display\n");
	temp=f;
	while(temp!=NULL)
	{
		printf("---->%d\n",temp->info);
		temp=temp->next;
	}
	printf("out\n");
}

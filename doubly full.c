// insert elements in ascending order.
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *prev;
	int info;
	struct node *next;
	
}nodetype;
nodetype *insert(nodetype *);
void display(nodetype *,nodetype *);
void *sort(nodetype *);
int main()
{
	struct node *left=NULL,*right=NULL;
	int choice;
	do
	{
		printf("\n1. insert\n2. display\n3. sort");
		printf("Enter your choice :  ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				right=insert(right);
				if(right->prev==NULL)
				left=right;
				break;
			case 2:
				display(right,left);
				break;	
				case 3:
					sort(left);
					break;
				default:
					break;
		}
		
	}while(choice<=3);
}

nodetype *insert(nodetype *right)
{
	nodetype *p;
	int x;
	printf("enter the number\n");
	scanf("%d",&x);
	p=(nodetype*)malloc(sizeof(nodetype));
	p->info=x;
	if(right==NULL)
	{
		p->next=NULL;
		p->prev=NULL;
		right=p;
	}
	else
	{
		right->next=p;
		p->prev=right;
		right=p;
	}
	return right;
}
void *sort(nodetype *left)
{
	nodetype *i,*j;
	int temp;
	for(i=left;i->next!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			{
				if(i->info>j->info)
				temp=i->info;
				i->info=j->info;
				j->info=temp;
			}
		}
	}
}
void display(nodetype *right,nodetype *left)
{   struct node *temp1=left,*temp2=right;
	printf("\nleft to right  ");
	while(temp1!=NULL)
	{
		printf("%d ",temp1->info);
		temp1=temp1->next;
	}
	printf("\nright to left  ");
	while(temp2!=NULL)
	{
		printf("%d ",temp2->info);
		temp2=temp2->prev;
	}
}

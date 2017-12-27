//program to create doubly linked list and display elements from left to right and then fron right to left
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int info;
	struct node *next;
	
};
struct node *insert(struct node *);
void display(struct node *,struct node *);
void *sort(struct node *);
int main()
{
	struct node *left=NULL,*right=NULL;
	int choice;
	do
	{
		printf("\n1. insert\n2. display\n3. sort");
		printf("Enter our choice :  ");
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
				default:
					break;
		}
		
	}while(choice<=3);
}
struct node *insert(struct node *right)
{   int x;
	struct node *p=(struct node *)malloc(sizeof(struct node));
	printf("enter insertion element  :  ");
	scanf("%d",&x);
	p->info=x;
	p->next=NULL;
	p->prev=NULL;
	if(right==NULL)
	{
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
void display(struct node *right,struct node *left)
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

void *sort(struct node *left)
{
	struct node *i,*j;
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

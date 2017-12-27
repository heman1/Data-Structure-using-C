#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *createlist(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addbtw(struct node *start,int data,int pos);
struct node *delatbeg(struct node *start);
struct node *delatend(struct node *start);
struct node *delbtw(struct node *start,int pos);
//struct node *reverse_iteration(struct node *start);
int main()
{
	struct node *start=NULL;
	int choice,data,pos;
	do
	{
		printf("\n1.create list\n2.display\n3.count\n4.search\n5.insertion at beginning\n6.inserion at end\n7.insertionn in between\n8.deletion in beginning \n9.deletion at end\n10. deletion in between\n11.Reverse by iteration\n");
		printf("\n enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				start=createlist(start);
				break;
			case 2:
			    display(start);
			    break;
			case 3:
				count(start);
				break;
			case 4:
				printf("enter the element to be searched  : ");
				scanf("%d",&data);
				search(start,data);
				break;
			case 5:
				printf("enter the element to be inserted");
				scanf("%d",&data);
				start=addatbeg(start,data);
				break;
			case 6:
				printf("enter the element to be inserted");
				scanf("%d",&data);
				start=addatend(start,data);
				break;
			case 7:
				printf("enter the element to be inserted  ");
				scanf("%d",&data);
				printf("enter the position after which to insert  ");
				scanf("%d",&pos);
				start=addbtw(start,data,pos);	
				break;	
			case 8:
				start=delatbeg(start);
				break;
			case 9:
				start=delatend(start);
				break;
			case 10 :
				printf("enter the position from where you want to delete  ");
				scanf("%d",&pos);
				break;
			case 11 :
			   // start=reverse_iteration(start);
				break;
				
			default :
			    printf("wrong choice ");
				break;
										
					    
		}
	}while(choice<=12);
	
}
void display(struct node *start)
{
	struct node *t=start;
	if(start==NULL)
	{
		printf("\nthe list is empty ");
		return;
	}
	printf("list is :  \n");
	while(t)
	{
		printf("%d",t->info);
		t=t->link;
	}
	printf("\n\n");
	
}
void count(struct node *start)
{   int count=0;
	struct node *t=start;
	if(start==NULL)
	{
		printf("\nthe list is empty ");
		return;
	}
	printf("list is :  \n");
	while(t)
	{
		count++;
		t=t->link;
	}
	printf("no. of elements are %d",count);
}
void search(struct node *start,int item)
{
	struct node *t=start;
	int pos=1;
	while(t)
	{
		if(t->info==item)
		{
			printf("item %d foumd at position ",item,pos);
			return;
		}
		t=t->link;
		pos++;
	}
	printf("item %d not found onn list ",item);
}
struct node *addatbeg(struct node *start,int data)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->info=data;
	new->link=start;
	start=new;
	return start;
}
struct node *addatend(struct node *start,int data)
{
	struct node *new,*t;
	t=start;
	new=(struct node *)malloc(sizeof(struct node));
	while(t->link!=NULL)
	{
		t=t->link;
	}
	t->link=new;
	new->info=data;
	new->link=NULL;
	return start;
}
struct node *addbtw(struct node *start,int data,int pos)
{
	struct node *new,*t;
	t=start;
	new=(struct node *)malloc(sizeof(struct node));
	while(t->info!=pos)
	t=t->link;
	new->info=data;
	new->link=t->link;
	t->link=new;
	
	return start;
}
struct node *delatbeg(struct node *start)
{
	struct node *t=start;
	if(start==NULL)
	return;
	if(start->link==NULL)
	{
		free(start);
		start=NULL;
		return;
	}
	start=start->link;
	free(t);
	return start;
}
struct node *delatend(struct node *start)
{
		struct node *t=start;
	if(start==NULL)
	return;
	if(start->link==NULL)
	{
		free(start);
		start=NULL;
		return;
	}
	while(t->link->link!=NULL)
	{
		t=t->link;
	}
	free(t->link);
	t->link=NULL;
	return start;
}
struct node *delbtw(struct node *start,int pos)
{
		struct node *t=start,*t1=t->link;
	if(start==NULL)
	return;
	if(start->link==NULL)
	{
		free(start);
		start=NULL;
		return;
	}
	while((t->link->info)!=pos)
	{
		t=t->link;
	}
	t->link=t1->link;
	free(t1);
	return start;
	

}
struct node *createlist(struct node *start)
{
	int n,i,data;
	printf("enter the number of nodes  ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
	return start;
	printf("enter the element to be inserted : ");
	scanf("%d",&data);
	start=addatbeg(start,data);
	for(i=1;i<n;i++)
	{
		printf("enter the element to be inserted ");
		scanf("%d",&data);
		start=addatend(start,data);
	}
	return start;
}



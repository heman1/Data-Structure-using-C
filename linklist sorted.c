// sorted linked list (while insertion)..
#include<stdio.h>
#include<stdlib.h>
typedef struct node
	{
		int info;
		struct node *next;
	 }nodetype;
	 

nodetype *insert(nodetype *,int );
nodetype *del(nodetype *);
nodetype *dsp(nodetype *);
nodetype *start=NULL;
int main()
{
	
	int n,x;
	do
	 {
	 	printf("*******************MENU********************\n");
	 	printf("1. insertion \n2. deletion\n3. display\n");
	 	scanf("%d",&n);
	 	switch(n)
	 	{
		case 1:
	 		printf("enter the element to insert\t");
	 		scanf("%d",&x);
	 		start=insert(start,x);
	 		printf("%d   addres:%d\n",start->info,start->next);  // printing the value of atrt and its adress.
	 		break;
	 		
	 	case 2:
	 		start=del(start);
	 		printf("the element has been delete");
	 		break;
	 		
	 	case 3:
	 		dsp(start);
	 		break;
	 		
	 		
	 	default :
	 		printf("the choice was wrong\n");
	 		break;
	 	}

	  }while(n<4);
	  return 0;
}

nodetype *insert(nodetype *start,int x)
{
	nodetype *p;
	nodetype *temp;
	p=(nodetype*)malloc(sizeof(nodetype));
	p->info=x;
	if(start==NULL)
	{
		printf("Here is the first node\n");
		p->next=NULL;
		start=p;
	}
	else if(x<start->info)
	{
		p->next=start;
		start=p;
	}
	else 
	{
			temp=start;
			while(temp->next!=NULL&&(temp->next->info)<x)
			{
				temp=temp->next;
			}
			if(temp->next==NULL)
			{
				p->next=NULL;
				temp->next=p;
			}
			else
			{
			p->next=temp->next;
			temp->next=p;
			}
	}
	return start;
}


nodetype *del(nodetype *start)
{
	nodetype *temp;
	if(start==NULL)
	printf("linked list is empty\n");
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		free(temp);
	}
	return start;
}


nodetype *dsp(nodetype *start)
{
	nodetype *temp;
	if(start==NULL)
	printf("the linked list is empty\n");
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("%d ",temp->info);
			temp=temp->next;
		}
	}
	return start;
}

// SIMPLY LINK LIST...............
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
nodetype *end(nodetype *,int );
nodetype *start=NULL;
int main()
{
	
	int n,x;
	do
	 {
	 	printf("*******************MENU********************\n");
	 	printf("1. insertion \n2. deletion\n3. display\n4. Insert at end\n");
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
	 		
	 	case 4:
	 		printf("enter the element to be inserted at the end\n");
	 		scanf("%d",&x);
	 		start=end(start,x);
	 		break;
	 		
	 	default :
	 		printf("the choice was wrong\n");
	 		break;
	 	}

	  }while(n<5);
	  return 0;
}


nodetype *insert(nodetype *start,int x)
{
	nodetype *p;
 		p=(nodetype*)malloc(sizeof(nodetype));
		p->info=x;
		if(start==NULL)
	{
		printf("we have the first node here\n"); 
		p->next=NULL;
		start=p;
	}
	else
	{
		printf("the next node comes here\n");
		p->next=start;
		
		start=p;
	}
    return start;
    
}

nodetype *dsp(nodetype *start)
{
	nodetype *tp;
	tp=start;
	if(tp!=NULL)
	
	{
		printf("the elements are:\n");
		while(tp!=NULL)
		{
			printf("----> %d\n",tp->info);
			tp=tp->next;
		}
	}
	else
	printf("the linklist is empty\n");
	
}

nodetype *del(nodetype *start)
{
	if(start==NULL)
	{
		printf("the linklist is empty\n");
	}
	else
	{
	nodetype *temp;
	temp=start;
	start=start->next;
	free(temp);
    }
	return start;	
}

nodetype *end(nodetype *start,int x)
{
     nodetype *temp,*p;
     temp=start;
     while(temp->next!=NULL)
     {
     	temp=temp->next;
	 }
	 p=(nodetype*)malloc(sizeof(nodetype));
	 p->info=x;
	 temp->next=p;
	 p->next=NULL;
	 return start;
}

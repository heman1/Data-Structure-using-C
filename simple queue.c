//THE SIMPLE QUEUE OPERATION
#include<stdio.h>
#include<string.h>
# define max 10
int insert(int [],int ,int );
int del(int [],int ,int );
void dsp(int [],int ,int );


int main()
{
	int qu[max],x,ch,r=-1,f=-1;
	do
	{
	printf("\nchoose the given operation as per your choice\n1. insert\n2. delete\n3. display");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nenter the value to be inserted\n");
			scanf("%d",&x);
			r=insert(qu,r,x);
			if(r!=-1)
			f=0;              //works for the first insertion
			break;
		case 2:
			f=del(qu,r,f);    //f value should be returned as deletion takes place from front
			break;
		case 3:
			dsp(qu,r,f);      // a void function as no value to be returned
		default:
			printf("\nsomething went wrong");
			
				
	}
	}while(ch<4);
	return 0;
}

//****************function definition,,here we go go go go......********************************/


int insert(int qu[max],int r,int x) 
{
	if(r==(max-1))
	printf("\n the queue is full\n");
	else
	{
		r++;
		qu[r]=x;
	}
	return r;
}



int del(int qu[max],int r,int f)
{
	int x;
	if(f==-1||f==r+1)
	printf("the queue is empty\n");
	else
    {
		x=qu[f];
		printf("the number was deleted");
		f++;
		
    }
    return f;
}




void dsp(int qu[max],int r,int f)
{
	int i;
	if(f==-1||f==r+1)
	printf("nothing to display, the queue is empty\n");
	else
  {
	for(i=f;i<=r;i++)
	{ printf("the value at %dth index is %d\n",i,qu[i]);
    }
  }
}

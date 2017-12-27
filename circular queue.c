/// CIRCULAR QUEUE......
#include<stdio.h>
# define max 3
int insert(int [],int , int ,int );
int del(int [],int ,int );
void dsp(int [],int ,int );

int main()
{
	int cq[max],x,ch,r=-1,f=-1;
	do
	{
	printf("\nchoose the given operation as per your choice\n1. insert\n2. delete\n3. display");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nenter the value to be inserted\n");
			scanf("%d",&x);
			r=insert(cq,r,f,x);
			if(f==-1)
			f=r;              //f should increse to 0 for the very first time.
			break;
		case 2:
			f=del(cq,r,f);  // only alteration is for the f variable.
			if(f==-1)      // when f==r, means the last element in queue, therefore both the value f&r should be initialised to -1.
			r=-1;	       // returning variable is only f, therefore we have to change the r here.
			break;
		case 3:
			dsp(cq,r,f);      // a void function as no value to be returned
		default:
			printf("\nsomething went wrong");
				
	}
	}while(ch<4);
	return 0;
}

int insert(int cq[max],int r,int f,int x)
{
	if((f==0&&r==max-1)||(f==r+1))       // when the queue is full from 0 to max-1 OR the r has completed a circle and went
	printf("the queue is overflow\n");   // just at the back of f.
	else if(f>0&&r==max-1)				 // when r is at last and f is greater than 0
	{
		r=0;
		cq[r]=x;
	}
	else
	{
		r++;
		cq[r]=x;
	}
	
	return r;
	
}

int del(int cq[max], int r,int f)
{
	int x;
	if(f==-1&&r==-1)
	printf("the queue is underflow(empty)\n");
	else if(f==max-1)    // it means that f has reached the extreme end 
	{
		x=cq[f];		 // we have to delete the value at the extreme end and intialize f again to 0.
		f=0;
	}
	else if(f==r)        // it is the last element on the queue.
	{
		x=cq[f];
		f=-1;
		r=-1;
	}
	else
	{
		x=cq[f];
		f++;
	}
	return f;
}

void dsp(int cq[max],int r, int f)
{
	int i=f;
	if(f==-1&&r==-1)
	printf("nothing to display the queue is empty\n");
	if(f<=r)                                           // here r is ahead of f as in normal case
	{
		while(i<=r)
		{
			printf("the element at %dth position is --> %d\n",i,cq[i]);
			i++;
		}
	}
	else             
	{
		while(r<=f){
			printf("the element at %dth position is --> %d\n",i,cq[r]);
			r++;
		}
		while(i<=max-1){
			printf("the element at %dth position is --> %d\n",i,cq[i]);
			i++;
		}		
	}
}



/*bubble sort algorith*/
#include<stdio.h>
void bubblesort(int* ,int ,int );
void swap(int* ,int );

void bubblesort(int* a,int imin,int imax)
{
	int i,swag;
	do						// this has to be performed at least once because the value of the swag cannot be intialized before 
	{
		swag=0;
		for(i=imin+1;i<=imax;i++)  // the loop should run unless we havn't done at least one swap.
		{
			if(a[i]<a[i-1])
			{
				swap(a,i);
				swag=1;           // this will remark that at least one time the swapping is performed.
			}
		}
	}while(swag==1);
}

void swap(int* a,int i) 
{
	int temp;
	temp=a[i];
	a[i]=a[i-1];
	a[i-1]=temp;
}

int main()
{
	int n,i,a[20];
	printf("enter the number of elemnents\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubblesort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}

/*insertion sort=>$ no exchange only shifting.
$ also known as incremental sort.
$ one of the best sorting methods.
$ 40% faster than selection sort and twice as fast as bubble sort.
$ In this method the j is always one less than i,it compares with i untill j reaches -1.*/
void insertion(int* ,int );
void display(int* ,int );
#include<stdio.h>
int main()
{
	int a[20],i,n;
	printf("*************INSERTION SORT*************\nenter the number of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertion(a,n);
	display(a,n);
	return 0;	
} 

void insertion(int* a,int n)
{

	int temp,i,j;
	for(i=0;i<n;i++)
	{
		temp=a[i];   //this is the new number to be placed at appropriate positiion, we make it temp so that we do not loose the number when we are swapping
		j=i-1;       //j should be always one behind the the i, and starts comparing untill j reaches -1.
		while(j>=0&&temp<a[j]) //when j reaches -1 AND temp is already greater the while loop will not execute.
		{
			a[j+1]=a[j];  // the number is partially swapped but we still have temp there to complete it afterwards. 
			j--;
		}
		a[j+1]=temp;  //as we have temp there we can complete the swapping now.
	}
	
}
void display(int* a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}



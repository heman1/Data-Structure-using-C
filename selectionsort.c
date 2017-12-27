/*SELECTION sort=>$ in this we take the minimum element out of the series.
$ It is not applicable for large list.
$ the time complexity is O(n^2).
$ it is generaly used for large objects and small keys
$ it 60% faster than bubble sort*/

void selection(int* ,int );
void print(int* ,int );
#include<stdio.h>
int main()
{
	int a[20],i,n;
	printf("*****************SELECTION SORT*******************\nenter the number of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selection(a,n);
	print(a,n);
	return 0;
}

void selection(int* a,int n)
{
	int min,pos,i,j;
	for(i=0;i<n-1;i++)     //n-1 because at last in n-1 the array is already sorted for last two numbers.
	{
		min=a[i];          //taking the first element as min,then second, then third as per i.
		pos=i;
		for(j=i+1;j<n;j++) //i+1 bcoz dealing with only the elements other than min or which are not yet sorted.
		{
			if(min>a[j])
			{
				pos=j;     //grab the position whwn you find the min to interchange it after this loop.
				min=a[j];
			}
		}
		if(pos!=i)		   //check wheather you find a min or not.if u would have find min than this will be true. 
		{
			a[pos]=a[i];   //interchange the positions of real min and the min you created at beginning.
			a[i]=min;
		}
	}
}

void print(int* a,int n)
{
	int i;
	printf("the sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
}

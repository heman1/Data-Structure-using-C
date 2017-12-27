// binary search tree.......
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
}treetype;

treetype *insert(treetype *,int );
treetype *preorder(treetype *);
treetype *postorder(treetype *);
treetype *inorder(treetype *);
treetype *del(treetype *,int );
treetype *root=NULL;

int main()
{
	int ch,n,d;
	do
	{
		printf("***********BST MENU*************\n1. insert data\n2. preorder\n3. postorder \n4. inorder\n5. delete\t");
		scanf("%d",&ch);
		switch(ch)
		{
			
			case 1:
				printf("enter the number\n");
				scanf("%d",&n);
				root=insert(root,n);
				break;
			case 2:
				printf("preorder : ");
				preorder(root);
				break;
			case 3:
				printf("postorder : ");
				postorder(root);
			    break;
			case 4:
				printf("inorder : ");
				inorder(root);
				break;
			case 5:
				printf("enter the number to be deleted\t");
				scanf("%d",&d);
				del(root,d);
		}
	}while(ch<6);
	return 0;
}

treetype *insert(treetype *rt,int n)
{
	if(rt==NULL)
	{
		printf("it's a first node..\n'");
		rt->info=n;
		rt->left=NULL;
		rt->right=NULL;
	}
	else if(n>rt->info)
	rt=insert(rt->right,n);
	else if(n<rt->info)
	rt=insert(rt->left,n);
	return rt;
}
treetype *inorder(treetype *rt)
{
	if(rt==NULL)
	{
		printf("sorry man, the BST is empty\n");
		return rt;
	}
	else
	{
		inorder(rt->left);
		printf("%d",rt->info);
		inorder(rt->right);
	}
	return rt;
}
treetype *postorder(treetype *rt)
{
	if(rt==NULL)
	{
		printf("sorry man, the BST is empty\n");
		return rt;
	}
	else
	{
		inorder(rt->left);
		inorder(rt->right);
		printf("%d",rt->info);
	}
	return rt;
}
treetype *preorder(treetype *rt)
{
	if(rt==NULL)
	{
		printf("sorry man, the BST is empty\n");
		return rt;
	}
	else
	{
		printf("%d",rt->info);
		inorder(rt->left);
		inorder(rt->right);
	}
	return rt;
}
treetype *del(treetype *rt, int d)
{
	if(rt==NULL)
	{
		printf("sorry ma, the BST is empty\n");
		return rt;
	}
	else if()
}

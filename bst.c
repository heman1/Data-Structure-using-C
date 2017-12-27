// binary search tree.......
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
}treetype;

void insert(treetype **,int );
void preorder(treetype *);
void postorder(treetype *);
void inorder(treetype *);
void del(treetype **,int );
int height(treetype *);
int totalnodes(treetype *);
int leaf(treetype *);
int internal(treetype *);
treetype *root=NULL;

int main()
{
	int ch,n,d,h;
	do
	{
		printf("***********BST MENU*************\n1. insert data\n2. preorder\n3. postorder \n4. inorder\n5. delete\n6. Height\n7. number of nodes\n8. leaf nodes\n9. internal nodes\t");
		scanf("%d",&ch);
		switch(ch)
		{
			
			case 1:
				printf("enter the number\n");
				scanf("%d",&n);
				insert(&root,n);
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
				del(&root,d);
				break;
			case 6:
				printf("the height is : %d",height(root));
				break;
			case 7:
				printf("the total number of nodes are : %d",totalnodes(root));
				break;
			case 8:
				printf("the total number of leaf nodes are %d",leaf(root));
				break;
			case 9:
				printf("the total number of non leaf(internal) nodes are : %d",internal(root));
		}
	}while(ch<10);
	return 0;
}
// function goes here....................
void insert(treetype **rt, int n)
{
	if(*rt==NULL) //check whether it is the first root node?
	{
		
		*rt=(treetype*)malloc(sizeof(treetype)); //allocate memory
		if(*rt!=NULL)                            //check for the memory stored
		{
			(*rt)->info=n;			
			(*rt)->left=NULL;
			(*rt)->right=NULL;
		}
	}
		else if(n<((*rt)->info)) //here the rt will move to left which is then NULL
		insert(&((*rt)->left),n);// call the function and the new node will be created
		else
		insert(&((*rt)->right),n);
	
}

void preorder(treetype *rt)
{
	if(rt==NULL)
	{
		return;
	}
	else
	{
		printf("%d ",rt->info);
		preorder(rt->left);
		preorder(rt->right);
	}
	
}
void postorder(treetype *rt)
{
	if(rt==NULL)
	{
		return ;
	}
	else
	{
		postorder(rt->left);
		postorder(rt->right);
		printf("%d ",rt->info);
	}
}
void inorder(treetype *rt)
{
	if(rt==NULL)
	{
		return ;
	}
	else
	{
		inorder(rt->left);
		printf("%d ",rt->info);
		inorder(rt->right);
	}
}

void del(treetype **rt,int d)
{
	treetype *temp;
	if(*rt==NULL)
	{
	printf("key not found in BST\n");
	return;
	}
	else if(d>(*rt)->info)
	del(&(*rt)->right,d);
	else if(d<(*rt)->info)
	del(&((*rt)->left),d);
	else if(d=(*rt)->info)
	{
	
		if((*rt)->left==NULL)
		{
			temp=*rt;
			*rt=(*rt)->right;
			free(temp);
		}
		else if((*rt)->right==NULL)
		{
			temp=*rt;
			*rt=(*rt)->left;
			free(temp);
		}
		else
		{
			temp=((*rt)->right);
			while(temp->left!=NULL)
			temp=temp->left;
			(*rt)->info=temp->info;
			del(&(*rt)->right,temp->info);
			
		}
	}
}
//height of the tree..
int height(treetype *rt)
{

	int cl,cr;
	if(rt==NULL)
	return 0;
	else
	{
		cl=height(rt->left);
		cr=height(rt->right);
		
	
	/*while(temp->left!=NULL)
	{
		temp=temp->left;
		cl++;
	}
	temp=rt;
	while(temp->right!=NULL)
	{
		temp=temp->right;
		cr++;
	}*/
		if(cl>cr)
		return (cl+1);
		else
		return (cr+1);
	}
	
}

//number of nodes....
int totalnodes(treetype *rt)
{
	if(rt==NULL)
	return 0;
	else
	return (totalnodes(rt->left)+totalnodes(rt->right)+1);
	
}
//number of leaf nodes.
int leaf(treetype *rt)
{
	if(rt==NULL)
	return 0;
	else if(rt->left==NULL&&rt->right==NULL)
	return 1;
	else
	return(leaf(rt->left)+leaf(rt->right));
	
}
//number of internal nodes
int internal(treetype *rt)
{
	if(rt==NULL||(rt->left==NULL&&rt->right==NULL))
	return 0;
	else
	return(internal(rt->left)+internal(rt->right)+1);
}

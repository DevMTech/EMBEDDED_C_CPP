#include <stdio.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int value)
{	 
 	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
 	
	return newNode;
}


struct node* insertNode(struct node* root, int value)
{
	if(root == NULL)
	{	return createNode(value);
	}
	else
	{
		if(root->data < value)
		{
			root->right = insertNode(root->right, value);
		}
		else if(value < root->data)
		{
			root->left = insertNode(root->left, value);
		}
	}
	
	return root;
}

void inorder(struct node* root)
{	
	if(root == NULL)
	{	return;
	}
	
	inorder(root->left);
	
	printf("%d -> ", root->data);
	
	inorder(root->right);	
	
}

int main()
{	
	struct node* root = NULL;
	
	root = insertNode(root, 50);
	insertNode(root, 10);
	insertNode(root, 40);
	insertNode(root, 30);
	insertNode(root, 20);
	insertNode(root, 60);
	
	inorder(root);
	
	return 0;
}

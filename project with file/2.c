
#include<stdio.h>
#include<stdlib.h>
typedef struct element
{
	int value;
	struct element * left;
	struct element * right;
}node;

node * root = NULL;

void linkNode(node *n, node *r)
{
	if(n->value <= r->value)
	{
		if(r->left == NULL)
		{
			r->left = n;
		}
		else
		{
			linkNode(n, r->left);
		}
	}
	else
	{
		if(r->right == NULL)
		{
			r->right = n;
		}
		else
		{
			linkNode(n, r->right);
		}
	}
}
void printTree(node *r)
{

	if(r != NULL)
	{
		printf("{ %d }", r->value);
		printTree(r->left);
		printTree(r->right);
	}
}

node * searchNode(int v, node *r)
{

	if(r->value == v)
	{
		return r;
	}
	else
	{
		if(v <=r->value)
		{
			if(r->left==NULL)
			{
				return NULL;
			}
			else
			{
				searchNode(v, r->left);
			}
		}
		else
		{
			if(r->right==NULL)
			{
				return NULL;
			}
			else
			{
				searchNode(v, r->right);
			}
		}
	}
}
node *getSuccessor(node *n)
{
	if(n->left == NULL)
	{
		return n;
	}
	else
	{
		getSuccessor(n->left);
	}
}
node *parent(node *n , node *r)
{
	// we alredy checked that n is not the root and n is exist
	if(n->value <= r->value)
	{
		if(r->left->value == n->value)
		{
			return r;
		}
		else
		{
			parent(n , r->left);
		}
	}
	else
	{
		if(r->right->value == n->value)
		{
			return r;
		}
		else
		{
			parent(n , r->right);
		}
	}

}
void deleteNode(node *n)
{
	int x;
	node *successor, *p;
	if(n->left != NULL && n->right != NULL)
	{
		successor = getSuccessor(n->right);
		x = successor->value;
		deleteNode(successor);
		n->value = x;
		return;
	}

	if(n->left == NULL && n->right == NULL)
	{

		if(n == root)
		{
			root = NULL;
		}
		else
		{
			p = parent(n , root);
			if(p->left == n)
			{
				p->left = NULL;
			}
			else
			{
				p->right = NULL;
			}

		}
		free(n);
		return;
	}
	if(n->left != NULL && n->right == NULL)
	{
		x = n->left->value;
		deleteNode(n->left);
		n->value = x;
		return;
	}
	if(n->left == NULL && n->right != NULL)
	{
		x = n->right->value;
		deleteNode(n->right);
		n->value = x;
		return;
	}

}
main()
{
    FILE *file;
    file=fopen("FILE.txt","a");
    if(file==NULL)
    {
        printf("file doesn't create\n");
    }
	printf("to add node press 1\n");
	printf("to search node press 2\n");
	printf("to delete node press 3\n");
	node *n, *n1;
	int x;
	printf("choose operation: "); scanf("%d",&x);
	while(x==1 || x==2 || x==3)
	{

		if(x==1)//adding node
		{
				int v;
				n = (node * ) malloc(sizeof(node));
				n -> left = NULL;
				n -> right = NULL;
				printf("inter node value: "); scanf("%d", &n->value);
				if(root == NULL)
				{
					root = n;
				}
				else
				{
					linkNode(n, root);
				}

		}
		if(x==2)// search node
		{
			int v;
			printf("value of node you search: ");
            scanf("%d",&v);
			if(root == NULL)
			{
				n1 = NULL;
			}
			else
			{
				n1 = searchNode(v, root);
			}
			if(n1 == NULL)
			{
				fprintf(file,"this node(%d) doesn't exist!\n",v);
			}
			else
			{
				fprintf(file,"the node %d  exist\n", n1->value);
			}
		}
		if(x==3)// delete node
		{
			int del;
			node *n1;
			printf("the node value: "); scanf("%d",&del);
			if(root == NULL)
			{
				printf("\n Tree is empty!\n");
			}
			else
			{
				n1 = searchNode(del, root);
				if(n1 == NULL)
				{
					printf("\nNode does not exist!");
				}
				else
				{
					deleteNode(n1);
				}
			}
		}
		printf("\nOur tree now:\n");
		printTree(root);
		printf("\nchoose operation: "); scanf("%d",&x);
		fclose(file);
	}
}

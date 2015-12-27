#include <iostream>
#include <stdio.h>
#include <math.h> 

using namespace std;

struct Node{
	int value ;
	int height;
	int lv;
	Node* left ;
	Node* right ;

	Node(int v = 0,int lvv = 0,Node* l = 0,Node* r = 0) 
	{
		value = v;
		lv = lvv;
		left = l;
		right = r;
	}
};

int getHeight(Node* n)
{
	if (n == 0)
	{
		return -1;	
	}
	else
	{
		return n->height;
	}
}

int setHeight(Node* root)
{
	return 1+max(getHeight(root->left),getHeight(root->right));
}

int checkHeight(Node* root)
{
	return getHeight(root->right) - getHeight(root->left);
}

void rotateLeftChild(Node*& root)
{
	Node* tmp = root->left;
	if (checkHeight(tmp) == 1)
	{
		Node* tmp2 = tmp->right;
		root->left = tmp2;
		tmp->right = tmp2->left;
		tmp2->left = tmp;
		tmp->height = setHeight(tmp);
		tmp2->height = setHeight(tmp2);
		tmp = tmp2;
	}
	root->left = tmp->right;
	tmp->right = root;
	root->height = setHeight(root);
	tmp->height = setHeight(tmp);
	root = tmp;
}

void rotateRightChild(Node*& root)
{
	Node* tmp = root->right;
	if (checkHeight(tmp) == -1)
	{
		Node* tmp2 = tmp->left;
		root->right = tmp2;
		tmp->left = tmp2->right;
		tmp2->right = tmp;
		tmp->height = setHeight(tmp);
		tmp2->height = setHeight(tmp2);
		tmp = tmp2;
	}
	
	root->right = tmp->left;
	tmp->left = root;
	root->height = setHeight(root);
	tmp->height = setHeight(tmp);
	root = tmp;
}

void rebalanceNode(Node*& root)
{
	int currentHeight = checkHeight(root);
	if (currentHeight == -2)
	{
		rotateLeftChild(root);
	}
	else if (currentHeight == 2)
	{
		rotateRightChild(root);
	}
}

void insert(Node*& root, int x,int lv)
{
  	if(root == 0) {
    	root = new Node(x,lv);
    	root->height = setHeight(root);
    	return;
  	}
  	if(x > root->value)
  	{	
  		lv +=1;
    	insert(root->right, x,lv);
    	root->height = setHeight(root);
    	rebalanceNode(root);
  	}
  	else if(x < root->value)
  	{	
  		lv +=1;
    	insert(root->left, x,lv);
    	root->height = setHeight(root);
    	rebalanceNode(root);
  	}
}

int find(Node*& root,int x)
{
	if (root == 0)
	{
		return 0;
	}
	if (root->value == x)
	{
		return 1;
	}

	if(x > root->value)
	{    
		find(root->right, x);
	}
 	else if(x < root->value)
    {	
    	find(root->left, x);
    }
}

void print(Node*& root)
{
	if (root->right == 0 && root->left == 0)
	{
		for (int i = 0; i <(root->lv)*3 ; ++i)
		{
			cout<<".";
		}
		cout<<"* ";
		cout<<root->value;
		printf(" %d\n",checkHeight(root));

		return;
	}

	if (root->right !=0)
	{
		 print(root->right);
	}

	for (int i = 0; i <(root->lv)*3 ; ++i)
	{
		cout<<".";
	}
	cout<<"* ";
	cout<<root->value;
	printf(" %d\n",checkHeight(root));

	if (root->left !=0)
	{
		print(root->left);
	}
}

//max to min  (right to left)
void printValue(Node* root)
{
	if (root->right == 0 && root->left == 0)
	{
		cout<<root->value;
		printf("\n");
		return;
	}

	if (root->right !=0)
	{
		 printValue(root->right);
	}

	cout<<root->value;
	printf("\n");

	if (root->left !=0)
	{
		printValue(root->left);
	}
}

int main()
{
	int n ;
	cin>>n;
	Node* r = 0;

	for (int i = 0; i < n; ++i)
	{
		int num1,num2;
		cin>>num1>>num2;
		if (num1 == 1)
		{
			insert(r,num2,0);
			// cout<<"\n";
			// print(r);
			// cout<<"\n";
		}
		else if (num1 == 2)
		{
			printf("%d\n",find(r,num2));
		}

	}
}
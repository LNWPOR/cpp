#include <iostream>
#include <stdio.h>

using namespace std;

struct Node{
	int value = 0 ;
	int lv = 0;
	int countR = 0;
	Node* left = 0 ;
	Node* right = 0 ;

	Node(int v = 0,int lvv = 0,int crl = 0,Node* l = 0,Node* r = 0) 
	{
		value = v;
		lv = lvv;
		countR = crl;
		left = l;
		right = r;
	}
};

void insert(Node*& root, int x,int lv)
{
  if(root == 0) {
    root = new Node(x,lv);
    return;
  }
  if(x > root->value)
  {
  	lv +=1;
  	root->countR += 1;
    insert(root->right, x,lv);

  }
  else if(x < root->value)
  {
  	lv += 1;
  	//root->countLR += 1;
    insert(root->left, x,lv);
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

Node* findMin(Node* r)
{
	while(r->left !=0)
		r = r->left;
	return r;
}

void deleteNode(Node*& root,int x)
{
	if (root == 0)
	{
		return;
	}
	else if (x > root->value)
	{
		deleteNode(root->right,x);
	}
	else if (x < root->value)
	{
		deleteNode(root->left,x);
	}
	else if(x == root->value)
	{
		if (root->left == 0 && root->right ==0)
		{
			Node* tmp = root;
			root = 0;
			delete tmp;
		}
		else if (root->right == 0 && root->left != 0)
		{
			Node* tmp = root;
			root = root->left;
			delete tmp;
		}
		else if (root->right != 0 && root->left == 0)
		{
			Node* tmp = root;
			root = root->right;
			delete tmp;
		}
		else if (root->right != 0 && root->left != 0)
		{
			Node* minRight = findMin(root->right);
			root->value = minRight->value;
			deleteNode(root->right,minRight->value);
		}

	}
	return;
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
		printf("\n");

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
	printf("\n");

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
		else if (num1 == 3)
		{
			deleteNode(r,num2);
			// cout<<"\n";
			// print(r);
			// cout<<"\n";
		}
	}

}
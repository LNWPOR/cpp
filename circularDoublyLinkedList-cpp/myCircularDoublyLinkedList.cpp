#include <cstdio>

struct ListNode{
	int value;
	ListNode* right;
	ListNode* left;
	ListNode* tail;
	int totalNode = 0;

	ListNode(int v,ListNode* r = 0,ListNode* l = 0,ListNode* t = 0) 
	{
		value = v;
		right = r;
		left = l;
		tail = t;
	}	
};

void print_list(ListNode* header)
{
  ListNode* list = header->right;
  while(list != 0) {
    printf("%d\n", list->value);
    if (header == header->tail)
	{
		break;
	}
    list = list->right;
  }
}

void insertFront(ListNode* header,int v)
{	
	ListNode* node = new ListNode(v);
	if (header->right == 0)
	{
		header->right = node;
		node->left = header;
		header->tail = node;
		header->tail->right = header;
		header->left = header->tail;
	}
	else
	{
		node->right = header->right;
		node->left = header;
		header->right->left = node;
		header->right = node;
	}
	header->totalNode += 1;
}

int countNode(ListNode* header)
{	
	int count=0;
	while(header !=0)
	{
		count++;
		if (header == header->tail)
		{
			break;
		}
		header = header->right;
	}
	return count-1;
}

//delete node at index p
void deleteNode(ListNode* header,int p)
{
	ListNode* list = header;
	for (int i = 1; i < p; ++i)
	{
		list=list->right;
	}

	if (p == header->totalNode)
	{
		if (header->totalNode == 1)
		{
			header->tail = 0;
		}
		else
		{
			header->tail = list;
		}
	}
	
	ListNode* tempList = list->right;
	if (p == header->totalNode)
	{
		list->right = header;
	}
	else
	{
		list->right = tempList->right;
	}

	tempList->right->left = list;
	delete tempList;
	header->totalNode -= 1;
}

void insertBack(ListNode* header,int v)
{	
	if(header->totalNode>0)
	{
		ListNode* aNode = new ListNode(v);
		header->tail-> right = aNode;
		aNode->left = header->tail;
		header->tail = aNode;
		aNode->right = header;
		header->left = aNode;
		header->totalNode += 1;
	}else if(header->totalNode == 0)
	{
		insertFront(header,v);
	}
}

int main()
{
	int n;
	scanf("%d\n",&n);
	ListNode* header = new ListNode(0);

	for (int i = 0; i < n; i++)
	{		
		int num;
		char c;
		scanf("\n%c",&c);
		
		if(c == 'I')
		{	
			scanf("%d",&num);
			insertFront(header,num);
		}
		else if(c == 'D')
		{
			scanf("%d",&num);
			if (num <= header->totalNode)
			{
				deleteNode(header,num);
			}
		}
		else if(c == 'A')
		{
			scanf("%d",&num);
			insertBack(header,num);
		}
		else if (c == 'P')
		{
			print_list(header);
		}
		else if(c == 'T')
		{
			printf("%d\n", header->totalNode);
		}	
	}
}
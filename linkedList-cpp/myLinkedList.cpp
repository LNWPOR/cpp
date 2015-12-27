#include <cstdio>

struct ListNode{
	int value;
	ListNode* next;
	ListNode* tail;
	int totalNode = 0;

	ListNode(int v,ListNode* n = 0,ListNode* t = 0) 
	{
		value = v;
		next = n;
		tail = t;
	}	
};

void print_list(ListNode* header)
{
  ListNode* list = header->next;
  while(list != 0) {
    printf("%d\n", list->value);
    list = list->next;
  }
}

void insertFront(ListNode* header,int v)
{	
	ListNode* node = new ListNode(v);
	if (header->next == 0)
	{
		header->next = node;
		header->tail = node;
	}
	else
	{
		node->next = header->next;
		header->next = node;
	}
	header->totalNode += 1;
}

int countNode(ListNode* header)
{	
	int count=0;
	while(header !=0)
	{
		count++;
		header = header->next;
	}
	return count-1;
}

//delete node at index p
void deleteNode(ListNode* header,int p)
{
	ListNode* list = header;
	for (int i = 1; i < p; ++i)
	{
		list=list->next;
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

	ListNode* tempList = list->next;
	list->next = tempList->next;
	delete tempList;
	header->totalNode -= 1;
}

void insertBack(ListNode* header,int v)
{	
	if(header->totalNode>0)
	{
		ListNode* aNode = new ListNode(v);
		header->tail-> next = aNode;
		header->tail = aNode;
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
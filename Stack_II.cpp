#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node 
{
	int data;
	node* next;
};

node* push(node* root, int val)
{
	if(root == NULL)
	{
		root = new node;
		root->data = val;
		root->next = NULL;
		return root;
	}
	
	node* iter = root;
	
	while(iter->next != NULL)
	{
		iter = iter->next;
	}
	
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	
	iter->next = temp;
	
	return root;
}

int pop(node* root)
{
	if(root == NULL)
	{
		printf("List is empty!");
		return -1;
	}
	
	if(iter->next == NULL)
	{
		int rvalue = root->data;
		free(root);
		return rvalue;
	}
	
	node* iter = root;

	while(iter->next->next != NULL)
	{
		iter = iter->next;
	}
	
	node* temp = iter->next;
	int rvalue = temp->data;
	iter->next = NULL;
	
	free(temp);
	return rvalue;
}

int main()
{
	node* list = new node;
	list = NULL;
	list = push(list, 10);
	
	printf("%d", list->data);
}







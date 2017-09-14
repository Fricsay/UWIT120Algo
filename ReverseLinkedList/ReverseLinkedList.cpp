// ReverseLinkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef struct _NODE {
	int Value;
	_NODE* Next = NULL;
}NODE, *PNODE;

NODE* LinkedListInit(int Data[], int count)
{
	NODE *ptrHead = NULL;
	NODE *ptrTemp = NULL;

	ptrHead = new NODE();
	ptrHead->Value = Data[0];
	ptrTemp = ptrHead;

	for (int i = 1; i < count; i++)
	{
		NODE *ptrNode = new NODE();

		//assign the data to the node->data
		ptrNode->Value = Data[i];

		//mode the temp node to the next
		ptrTemp->Next = ptrNode;
		ptrTemp = ptrNode;
	}

	return ptrHead;
}

/************************************************************************
Every time when we need a reverse order we can always leverage the stack
Here is a recursive version to use thread stack to reverse the linked list
************************************************************************/
NODE* ReverseRecursive(NODE* head)
{
	//list does not exist
	if (head == NULL)
	{
		return NULL;
	}

	//list has only one node
	if (head->Next == NULL)
	{
		return head;
	}

	NODE *rest = ReverseRecursive(head->Next);

	head->Next->Next = head;
	head->Next = NULL;

	return rest;
}

/************************************************************************
This is the in-place version of reversing a linked list
************************************************************************/
NODE* ReverseInplace(NODE* head)
{
	//list does not exist
	if (head == NULL)
	{
		return NULL;
	}

	//list has only one node
	if (head->Next == NULL)
	{
		return head;
	}

	NODE *prev = NULL;
	NODE *current = head;
	NODE *next = NULL;

	while (current != NULL)
	{
		next = current->Next;
		current->Next = prev;
		prev = current;
		current = next;
	}

	return prev;
}

int main()
{
	int data[] = { 1, 2, 3, 4, 5, 6, 7};

	//initialize the singly linked list with the data array
	NODE* myList = LinkedListInit(data, 7);

	if (!myList)
	{
		printf("main: cannot create the list\n");
		return 0;
	}

	printf("Original List\n");
	printf("========================================\n");

	NODE* ptrTemp = myList;

	//print the original singly linked list
	for (int i = 0; (ptrTemp != NULL); i++)
	{
		printf("Node %d: %d\n", i, ptrTemp->Value);
		ptrTemp = ptrTemp->Next;
	}

	printf("\nReverse List - Recursive\n");
	printf("========================================\n");

	NODE* recursive = ptrTemp = ReverseRecursive(myList);

	for (int i = 0; (ptrTemp != NULL); i++)
	{
		printf("Node %d: %d\n", i, ptrTemp->Value);
		ptrTemp = ptrTemp->Next;
	}

	printf("\nReverse List - In-place\n");
	printf("========================================\n");

	NODE* inplace = ptrTemp = ReverseInplace(recursive);

	for (int i = 0; (ptrTemp != NULL); i++)
	{
		printf("Node %d: %d\n", i, ptrTemp->Value);
		ptrTemp = ptrTemp->Next;
	}

/*RESULT
	Original List
	========================================
	Node 0: 1
	Node 1: 2
	Node 2: 3
	Node 3: 4
	Node 4: 5
	Node 5: 6
	Node 6: 7

	Reverse List - Recursive
	========================================
	Node 0: 7
	Node 1: 6
	Node 2: 5
	Node 3: 4
	Node 4: 3
	Node 5: 2
	Node 6: 1

	Reverse List - In-place
	========================================
	Node 0: 1
	Node 1: 2
	Node 2: 3
	Node 3: 4
	Node 4: 5
	Node 5: 6
	Node 6: 7
*/

    return 0;
}




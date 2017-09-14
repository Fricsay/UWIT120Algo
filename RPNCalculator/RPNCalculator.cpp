// RPNCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"
#include "limits.h"
#include <stdio.h>  


#define DEFAULT_SIZE 256

//STACK structure
typedef struct Stack {
	int* array;
	int idx;
}STACK, *PSTACK;

//STACK functions
void STACK_Init(PSTACK myStack);
bool STACK_isEmpty(PSTACK myStack);
int STACK_size(PSTACK myStack);
void STACK_push(PSTACK myStack, int value);
int STACK_pop(PSTACK myStack);
int STACK_peek(PSTACK myStack);

//RPNCalculator
void RPNCalculator();

void RPNCalculator()
{
	STACK myStack;
	STACK_Init(&myStack);

	int ch;
	int result;
	int pop1;
	int pop2;

	printf("use ctrl+break to leave the calc\n");

	while (ch = getchar())
	{
		int value = ch - '0';

		if (value <= 9 && value >= 0)
		{
			STACK_push(&myStack, value);
			printf("=%d\n", value);
		}
		else if (ch == '+')
		{
			pop1 = STACK_pop(&myStack);
			pop2 = STACK_pop(&myStack);
			STACK_push(&myStack, pop2 + pop1);
			printf("=%d\n", STACK_peek(&myStack));
		}
		else if (ch == '-')
		{
			pop1 = STACK_pop(&myStack);
			pop2 = STACK_pop(&myStack);
			STACK_push(&myStack, pop2 - pop1);
			printf("=%d\n", STACK_peek(&myStack));
		}
		else if (ch == '*')
		{
			pop1 = STACK_pop(&myStack);
			pop2 = STACK_pop(&myStack);
			STACK_push(&myStack, pop2 * pop1);
			printf("=%d\n", STACK_peek(&myStack));
		}
		else if (ch == '/')
		{
			pop1 = STACK_pop(&myStack);
			pop2 = STACK_pop(&myStack);
			if (pop1 == 0)
			{
				printf("RPNCalculator: Wrong Operation, cannot divide 0");
				break;
			}

			STACK_push(&myStack, pop2 / pop1);
			printf("=%d\n", STACK_peek(&myStack));
		}
		else if (ch == '=')
		{
			printf("=%d\n", STACK_peek(&myStack));
		}
	}
}



int main()
{

	RPNCalculator();

    return 0;
}

void STACK_Init(PSTACK myStack)
{
	myStack->idx = 0;
	myStack->array = (int*)malloc(sizeof(int)*DEFAULT_SIZE);

	if (myStack->array == NULL)
	{
		printf("STACK_Init: failed to allocate memory\n");
		return;
	}
}

bool STACK_isEmpty(PSTACK myStack)
{
	return (myStack->idx == 0);
}

int STACK_size(PSTACK myStack)
{
	return myStack->idx;
}

void STACK_push(PSTACK myStack, int value)
{
	if (myStack->idx == DEFAULT_SIZE)
	{
		printf("STACK_push: Stack overflow, cannot push\n");
		return;
	}

	myStack->array[myStack->idx] = value;
	myStack->idx++;
}

int STACK_pop(PSTACK myStack)
{
	if (STACK_isEmpty(myStack))
	{
		printf("STACK_pop: Stack underflow, cannot pop, value cannot be used\n");
		return INT_MIN;
	}

	myStack->idx--;

	int pop = myStack->array[myStack->idx];
	myStack->array[myStack->idx] = INT_MIN;
	
	return pop;
}

int STACK_peek(PSTACK myStack)
{
	if (STACK_isEmpty(myStack))
	{
		printf("STACK_peek: Stack is empty\n");
		return INT_MIN;
	}

	return myStack->array[myStack->idx -1];
}

#include "main.h"


/**
 * push - push item to a stack
 * @x: The item to be pushed
 * Return: void
 *
 * Desciption: add item to the top of a stack and return void
 **/


void push(int x)
{
	stack_t *newnode = NULL;

	if (argc < 2)
	{
		perror("L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	if (!(atoi(argv[1])))
	{
		fprintf(stderr, "L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		free(newnode);
		exit(EXIT_FAILURE);
	}

	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->n = x;
	
	if (!top)
		top = newnode;
	else
	{
		newnode->prev = top;
		top->next = newnode;
		top = newnode;
	}
}


/**
 * pall - prints the items in a stack
 * Return: void
 *
 * Description: prints items in a stack and returns void
 **/

void pall()
{
	stack_t *temp = NULL;

	if (!top)
		exit(EXIT_SUCCESS);
	else
	{
		temp = top;
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}

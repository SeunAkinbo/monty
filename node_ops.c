#include "monty.h"

/**
 * addnode - Add node to the begining of the linked list
 * @top: The first node in the stack
 * @n: The value of the list item
 * Return: void
 **/

void addnode(stack_t **top, int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newnode);
		closefile();
		freeline();
		exit(EXIT_FAILURE);
	}

	newnode->next = *top;
	newnode->prev = NULL;
	newnode->n = n;

	if (*top)
		(*top)->prev = newnode;
	*top = newnode;
}

/**
 * node_count - counts the number of nodes in a stack
 * @stack: The stack doubly linked list
 * Return: The node count
 **/

unsigned int node_count(stack_t **stack)
{
	unsigned int count = 0;
	stack_t *curr;

	curr = *stack;

	while (curr)
	{
		count++;
		curr = curr->next;
	}
	free(curr);
	return (count);
}

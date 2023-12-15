#include "monty.h"

/**
 * push - push item to a stack
 * @stack: A doubly linked list
 * @line_number: The item to be pushed
 * Return: void
 **/

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int value;

	if (file_items->num_tokens < 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		closefile();
		freeline();
		exit(EXIT_FAILURE);
	}

	if ((file_items->arg == NULL || !isdigit(*file_items->arg))
		&& *file_items->arg != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		closefile();
		freeline();
		exit(EXIT_FAILURE);
	}

	value = atoi(file_items->arg);
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newnode);
		closefile();
		freeline();
		exit(EXIT_FAILURE);
	}
	newnode->next = *stack;
	newnode->prev = NULL;
	newnode->n = value;

	if (*stack)
		(*stack)->prev = newnode;
	*stack = newnode;
}

/**
 * pop - Pops item at the top of the stack
 * @stack: Doubly linked list
 * @line_number: The file line number
 * Return: void
 *
 * Description: Pops item at the top of a
 *		stack and returns void
 **/
void pop(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = (*stack)->next;
}

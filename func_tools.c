#include "monty.h"


/**
 * push - push item to a stack
 * @stack: A doubly linked list
 * @line_number: The item to be pushed
 * Return: void
 *
 * Desciption: add item to the top of a stack and return void
 **/


void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (argv[1] == NULL || !isdigit(*argv[1]) && *argv[0] != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argv[1]);

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(newnode);
		exit(EXIT_FAILURE);
	}

	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->n = value;

	if (*stack)
	{
		(*stack)->prev = newnode;
		newnode->next = *stack;
	}
	*stack = newnode;
}


/**
 * pall - prints the items in a stack
 * @stack: Doubly linked list stack
 * @line_number: The file line number
 * Return: void
 *
 * Description: prints items in a stack and returns void
 **/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	if (!*stack)
		exit(EXIT_SUCCESS);

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * pint - Print item at the top of the stack
 * @stack: The singly linked list
 * @line_number: The file line number
 * Return: void
 *
 * Description: Function prints the item at the to
 *		 of a stack and returns void
 **/


void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
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




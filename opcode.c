#include "monty.h"

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
	stack_t *temp = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		closefile();
		freeline();
		free(temp);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (temp)
		free(temp);
}

/**
 * push - push item to a stack
 * @stack: A doubly linked list
 * @line_number: The item to be pushed
 * Return: void
 **/

void push(stack_t **stack, unsigned int line_number)
{
	int value, i = 0, ar_flag = 0;

	if (file_items->arg)
	{
		if (file_items->arg[0] == '-')
			i++;
		for (; file_items->arg[i] != '\0'; i++)
		{
			if (file_items->arg[i] > 57 || file_items->arg[i] < 48)
				ar_flag = 1;
		}
		if (ar_flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			closefile();
			freeline();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		closefile();
		freeline();
		exit(EXIT_FAILURE);
	}

	value = atoi(file_items->arg);
	addnode(stack, value);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: The doubly linked list of the stack
 * @line_number: The line number of the file
 * Return: void
 **/

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		closefile();
		freeline();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * nop - The function does nothing
 * @line_number: The file operation command line number
 * @stack: The doubly linked list of the stack
 * Return: void
 **/

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	return;
}

/**
 * rotl - rotates the stack to the top
 * @stack: The doubly linked list of the stack
 * @line_number: The file operation command line number
 * Return: void
 **/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom, *temp;
	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	bottom = *stack;
	temp = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = bottom;
	*stack = temp;
}

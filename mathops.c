#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: The stack doubly linked list
 * @line_number: The line numer of the file command
 * Return: void
 **/

void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
				line_number);
		closefile();
		freeline();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;

	if (temp)
		free(temp);
}

/**
 * sub - Subtracts the top element of the stack from the
 *	second top element of the stack
 * @stack: The stack doubly linked list
 * @line_number: The line number of the file command
 * Return: void
 **/

void sub(stack_t **stack, unsigned int line_number)
{
	int diff;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
				line_number);
		closefile();
		freeline();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	diff = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = diff;
	*stack = (*stack)->next;

	if (temp)
		free(temp);
}

/**
 * _div - Divides the second top element of the stack
 *	by the top element of the stack.
 * @stack: The stack doubly linked list
 * @line_number: The line number of the file command
 * Return: void
 **/

void _div(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
				line_number);
		closefile();
		freeline();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
				line_number);
		closefile();
		freeline();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	*stack = (*stack)->next;

	if (temp)
		free(temp);
}


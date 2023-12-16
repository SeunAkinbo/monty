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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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

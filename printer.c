#include "monty.h"

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
	stack_t *temp;
	(void)line_number;

	if (!*stack)
		exit(EXIT_SUCCESS);

	temp = *stack;

	if (!temp)
		return;

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

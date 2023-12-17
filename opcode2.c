#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: The doubly linked list
 * @line_number: The command line number in file
 * Return: void
 **/


void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom;
	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom = *stack;
	while (bottom->next)
		bottom = bottom->next;

	bottom->next = *stack;
	bottom->prev->next = NULL;
	bottom->prev = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}

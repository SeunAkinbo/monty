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
	(void)line_number;

	if (!*stack)
		return;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		stack = &(*stack)->next;
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
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: The singly linked list
 * @line_number: The file line number
 * Return: void
 **/

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
				line_number);
		closefile();
		freeline();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_number);
		closefile();
		freeline();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	putchar((char)(*stack)->n);
	putchar('\n');
}

/**
 * pstr - Prints the string at the top of the stack, followed by a new line
 * @stack: A doubly linked list representing the stack
 * @line_number: The line number in the Monty file
 * Return: void
 **/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	node = *stack;
	while (node)
	{
		if ((node->n > 127 || node->n <= 0))
			break;
		printf("%c", node->n);
		node = node->next;
	}
	printf("\n");
}

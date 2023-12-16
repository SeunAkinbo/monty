#include "monty.h"

/**
 * push - push item to a stack
 * @stack: A doubly linked list
 * @line_number: The item to be pushed
 * Return: void
 **/

void push(stack_t **stack, unsigned int line_number)
{
	int value, i = 0;

	if (!file_items->arg)
	{/* Null argument check */
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		closefile();
		freeline();
		exit(EXIT_FAILURE);
	}

	if (file_items->arg[0] == '-' && file_items->arg[1] == '\0')
	{/* Single argument check */
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		closefile();
		freeline();
		exit(EXIT_FAILURE);
	}
	/* Loop to check if argument contains only digits */
	for (; file_items->arg[i] != '\0'; ++i)
	{
		if (file_items->arg[i] < '0' || file_items->arg[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			closefile();
			freeline();
			exit(EXIT_FAILURE);
		}
	}
	/* Convert to integer and push */
	value = atoi(file_items->arg);
	addnode(stack, value);
}


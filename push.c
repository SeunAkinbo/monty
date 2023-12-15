#include "monty.h"

/**
 * push - push item to a stack
 * @stack: A doubly linked list
 * @line_number: The item to be pushed
 * Return: void
 **/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int value, i = 0, flag = 0;


	if (file_items->arg)
	{
		if (file_items->arg[0] == '-')
			i++;
		for (; file_items->arg[i] != '\0'; i++)
		{
			if (file_items->arg[i] > 57 || file_items->arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
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


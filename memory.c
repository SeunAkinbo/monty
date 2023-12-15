#include "monty.h"

/**
 * closefile - closes the opened file
 * Return: void
 *
 * Description: Closes the opened file process
 **/


void closefile(void)
{
	fclose(file_items->file);
}


/**
 * freeline - Frees the memory allocated during the getline function instance
 * Return: void
 *
 * Description: Frees the memory allocated
 *		during the getline instance
 **/

void freeline(void)
{
	free(file_items->line);
}


/**
 * free_stack - Frees the memory allocated to the stack
 * @stack: A doubly linked list
 * Return: void
 **/

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		free(stack);
		stack = temp->next;
	}
}

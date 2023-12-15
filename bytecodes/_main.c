#include "monty.h"


file_handler *file_items = NULL;


/**
 * main - The main function
 * @argc: Argument counter
 * @argv: Argument vector
 * Return: 0 on success, 1 otherwise
 **/

int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = get_file(argv[1]);

	file_items = malloc(sizeof(file_handler));
	if (!file_items)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	file_items->num_tokens = argc;
	file_items->line = NULL;
	file_items->file = file;
	file_items->arg = NULL;
	file_items->stack = NULL;
	execute_ops(file_items->line, file_items->stack);

	free(file_items->line);
	fclose(file_items->file);
	free_stack(file_items->stack);
	free(file_items);
	exit(EXIT_SUCCESS);
}

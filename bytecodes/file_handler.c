#include "monty.h"

/**
 * get_file - Opens the file
 * @arg: File path
 * Return: void
 **/

FILE *get_file(char *arg)
{
	FILE *file = fopen(arg, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * read_line - Reads each line ina file
 * @f: The file to be read
 * Return: -1 on fail > 0 on success
 **/

size_t read_line(FILE *f)
{
	char *line = NULL;
	size_t len = 0;
	size_t readline;
	size_t getline(char **buffer, size_t *size, FILE *f);

	readline = getline(&line, &len, f);
	if (readline > 0)
		file_items->line = line;
	free(line);
	return (readline);
}

/**
 * ops - Gets the operation token
 * @line: Line read from a file
 * Return: operation to be executed
 **/

char *ops(char *line)
{
	char *opcode;

	opcode = strtok(line, " \n\t\r");
	file_items->arg = opcode;
	return (opcode);
}

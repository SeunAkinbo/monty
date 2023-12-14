#include "monty.h"

/**
 * get_file - Opens the file
 * @arg: File path
 * Return: void
 **/

void get_file(char *arg)
{
	file = fopen(arg, "r");

	if (file == NULL)
	{
		fprint(stderr, "Error: Can't open file %s\n", arg);
		exit(EXIT_FAILURE);
	}

	file_items->file = file;
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

	readline = getline(&line, &len, f);
	if (readline != -1)
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

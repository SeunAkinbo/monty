#include "monty.h"

/**
 * get_file - Opens the file
 * @arg: File path
 * Return: void
 **/

FILE *get_file(char *arg)
{
	FILE *file = fopen(arg, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg);
		exit(EXIT_FAILURE);
	}

	return (file);
}

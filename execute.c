#include "monty.h"
/**
 * execute - Executes the given opertaion on the file
 * @file: The file to be read and operated on
 * Return: void
 **/
void execute(FILE *file)
{
	char *opcode, *line = NULL;
	size_t i, len = 0;
	unsigned int line_number = 0, found;

	ssize_t getline(char **line, size_t *len, FILE *file);
	instruction_t instructions[] = {
					{"push", &push}, {"pall", &pall},
					{"pint", &pint}, {"pop", &pop},
					{"swap", &swap}, {"add", &add},
					{"nop", &nop}, {"sub", &sub},
					{"div", &_div}, {"mul", &_mul},
					{"mod", &_mod}, {"pchar", &pchar},
					{"pstr", &pstr}, {NULL, NULL}};
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		file_items->line = line;
		opcode = strtok(line, " \n\t\r");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		file_items->arg = strtok(NULL, " \n\t\r");
		found = 0;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				found = 1;
				instructions[i].f(&file_items->stack, line_number);
				break; }
		}
		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			free(file_items);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
}

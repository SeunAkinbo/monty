#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char *opcode, *line = NULL;
	size_t i, len = 0;
	unsigned int line_number = 0;
	int found;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(args[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", args[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t\r");
		if (opcode == NULL)
			continue;

		found = 0;
		for (i = 0; instruction[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instruction[i].opcode) == 0)
			{
				found = 1;
				instruction[i].f(&stack, line_number);
				break;
			}
		}

		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}

#include "monty.h"


int main(int argc, char *argv[])
{
	FILE *file;
	char *opcode, *line = NULL;
	size_t i, len = 0;
	unsigned int line_number = 0;
	int found;
	int getline(char **line, size_t *len, FILE *file);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_items.num_tokens = argc ;

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	file_items.file = file;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		file_items.line = line;
		opcode = strtok(line, " \n\t\r");
		if (opcode == NULL)
			continue;

		found = 0;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				found = 1;
				instructions[i].f(&file_items.stack, line_number);
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

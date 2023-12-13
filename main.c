#include "monty.h"
file_handler *file_items = NULL;
/**
 *
 *
 *
 *
 **/

int main(int argc, char *argv[])
{
	FILE *file;
	char *opcode, *line = NULL;
	size_t i, len = 0;
	unsigned int line_number = 0;
	int found;
	int getline(char **line, size_t *len, FILE *file);

	instruction_t instructions[] = {
					{"push", &push},
					{"pall", &pall},
					{"pint", &pint},
					{"pop", &pop},
					{NULL, NULL}
	};

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	file_items->file = file;
	file_items->num_tokens = argc;
	file_items->line = NULL;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		file_items->line = line;
		opcode = strtok(line, " \n\t\r");
		if (opcode == NULL)
			continue;

		found = 0;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				found = 1;
				instructions[i].f(&file_items->stack, line_number);
				break;
			}
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

	free(line);
	free(file_items);
	fclose(file);
	exit(EXIT_SUCCESS);
}

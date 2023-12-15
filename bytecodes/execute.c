#include "monty.h"

/**
 * execute_ops - excutes the operation
 * @opcode: The operation to be executed
 * @stack: The doubly linked list to be operated on
 * Return: void
 **/


int execute_ops(char *line, stack_t *stack)
{
	instruction_t instruction[] = {
					{"push", &push},
					{"pall", &pall},
					{"pint", &pint},
					{"pop", &pop},
					{NULL, NULL}
	};
	int line_num = 0, i;
	char *opcode;

	while(read_line(file_items->file) > 0)
	{
		line_num++;

		opcode = strtok(line, " \n\r\t");
		if (!opcode)
			return (0);
		if (opcode && opcode[0] == '#')
			continue;

		file_items->arg = opcode;

		for (i = 0; instruction[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instruction[i].opcode) == 0)
			{
				instruction[i].f(&stack, line_num);
				break;
			}
		}

		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
		fclose(file_items->file);
		free_stack(file_items->stack);
		free(file_items);
		exit(EXIT_FAILURE);
	}
	return (1);
}


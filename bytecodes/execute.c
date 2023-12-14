/**
 * execute_ops - excutes the operation
 * @opcode: The operation to be executed
 * @stack: The doubly linked list to be operated on
 * Return: void
 **/


int execute_ops(char *opcode, stack_t *stack)
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

        while(read_line(file_items->file))
        {
                line_num++;

		opcode = strtok(file_items->line, " \n\r\t");
		if (!opcode)
			return (0);
		if (opcode && opcode[0] == '#')
			return (0);
		file_items->arg = strtok(NULL, " \n\r\t")

                for (i = 0; instruction[i].opcode != NULL; i++)
                {
                        if (strcmp(opcode, instruction[i].opcode) == 0)
                        {
                                instruction[i].f(&file_items->stack, line_num)
                                        break;
                        }
                }
                fprint(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
                free(file_items->line);
                fclose(file_items->file);
                free(file_items->arg);
                free_stack(file_items->stack);
                free(file_items);
                exit(EXIT_FAILURE);
        }
}


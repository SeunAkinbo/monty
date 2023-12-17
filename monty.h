#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>


/*DEFINING STRUCTS*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct File_content - a struct containing item of a line
 * @file: pointer to the file
 * @line: a pointer to the line read by getline
 * @num_tokens: number of tokens passed
 * @stack: pointer to the head
 */

typedef struct file_handler
{
	FILE *file;
	char *line;
	char *arg;
	int num_tokens;
	stack_t *stack;
} file_handler;


/*GLOBAL VARIABLE DECLARATION AND DEFINITION*/
extern file_handler *file_items;


/*FUNCTION PROTOTYPES*/

/*OPERATIONS CODES PROTOTYPES*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
int main(int argc, char *argv[]);
void addnode(stack_t **top, int n);
unsigned int node_count(stack_t **stack);

/*MATH OPERATION PROTOTYPES*/
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);


/*MEMORY MANAGEMENT PROTOTYPES*/
void closefile();
void freeline();
void free_stack(stack_t *stack);

/*PROCESS MANAGEMENT PROTOTYPES*/
void execute(FILE *file);
FILE *get_file(char *arg);
size_t read_line(FILE *f);
char *ops(char *line);


#endif /*MAIN_H*/

#include "monty.h"

/**
 * closefile - closes the opened file
 * Return: void
 *
 * Description: Closes the opened file process
 **/


void closefile(void)
{
	fclose(file_items->file);
}


/**
 * freeline - Frees the memory allocated during the getline function instance
 * Return: void
 *
 * Description: Frees the memory allocated
 *		during the getline instance
 **/

void freeline(void)
{
	free(file_items->line);
}
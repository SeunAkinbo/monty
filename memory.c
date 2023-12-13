#include "monty.h"

/** 
 * closefile - closes the opened file
 * Return: void
 *
 * Description: Closes the opened file process
 **/


void closefile()
{
	fclose(file_items->file);
}


/**
 * freeline - Frees the memory allocated during the getline function instance
 *
 * Return: void
 *
 * Description: Frees the memory allocated
 *		during the getline instance
 **/

void freeline()
{
	free(file_items->line);
}

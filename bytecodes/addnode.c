#include "monty.h"

/**
 * addnode - Adds node to the beginning of the stack
 * @head: The doublyn linked list
 * @n: The item to be added to the stack
 * Return: The updated node
 **/

void addnode(stack_t *head, int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = n;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (!head)
		head = newnode;
	else
	{
		head->prev = newnode;
		newnode->next = head;
		head = newnode;
	}
}

/**
 * addnode_queue - add newnode to the queue
 * @head: the first node in the queue
 * @bot: The last node in the queue
 * Return: void
 **/

void addnode_queue(stack_t *head, stack_t *bot, int n)
{
	stack_t *newnode;

	 newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = n;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (!head)
	{
		head = newnode;
		bot = newnode;
	}
	
	bot = NULL;
	while(bot->next)
		bot = bot->next;

	bot->next = newnode;
	newnode->prev = bot;
}

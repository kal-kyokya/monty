#include "monty.h"

/**
 * add_node_end - add node to the top
 * @h: head
 * @n: node data
 *
 * Return: nothing
 */
void add_node_end(stack_t **h, int n)
{
	stack_t *current, *new_node;

	current = *h;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (current == NULL)
	{
		*h = new_node;
		new_node->prev = NULL;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}


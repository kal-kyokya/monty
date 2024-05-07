#include "monty.h"

/**
 * add_node - add node to the top
 * @h: head
 * @n: node data
 *
 * Return: nothing
 */
void add_node(stack_t **h, int n)
{
	stack_t *current, *new_node;

	current = *h;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (current != NULL)
		current->prev = new_node;
	new_node->n = n;
	new_node->next = *h;
	new_node->prev = NULL;
	*h = new_node;
}


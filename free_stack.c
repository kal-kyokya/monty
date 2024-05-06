#include "monty.h"

/**
 * free_stack - add node to the top
 * @h: head
 *
 * Return: nothing.
 */
void free_stack(stack_t *h)
{
	stack_t *current, *next_node;

	current = h;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

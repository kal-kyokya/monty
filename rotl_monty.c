#include "monty.h"

/**
 * mrotl - Wraps around top sets to bottom.
 * @h: Adress of the top pointer.
 * @count: Line number.
 *
 * Return: Nothing.
 */
void mrotl(stack_t **h, unsigned int count)
{
	stack_t *temp, *current;
	(void)count;

	if (h == NULL || *h == NULL)
		return;
	current = temp = *h;
	*h = current->next;
	(*h)->prev = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
}

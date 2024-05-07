#include "monty.h"

/**
 * mrotr - Wraps around top sets to bottom.
 * @h: Adress of the top pointer.
 * @count: Line number.
 *
 * Return: Nothing.
 */
void mrotr(stack_t **h, unsigned int count)
{
	stack_t *temp, *current;
	(void)count;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
		return;
	current = temp = *h;
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	*h = current;
	(*h)->prev = NULL;
	current->next = temp;
}

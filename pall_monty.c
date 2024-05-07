#include "monty.h"

/**
 * mpall - prints all the values on the stack, starting from the top
 * @h: head
 * @count: line count or line number
 *
 * Return: nothing.
 */
void mpall(stack_t **h, unsigned int count)
{
	stack_t *current;
	(void)count;

	current = *h;
	if (current == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

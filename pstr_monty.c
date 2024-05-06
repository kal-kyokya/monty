#include "monty.h"

/**
 * mpstr - prints the string from the top to terminator.
 * @h: head
 * @count: line number
 *
 * Return: nothing.
 */
void mpstr(stack_t **h, unsigned int count)
{
	stack_t *current;

	current = *h;
	if (*h == NULL)
		printf("\n");
	else
	{
		while (current != NULL || current->n != 0)
		{
			printf("%c", current->n);
			current = current->next;
		}
		printf("\n");
	}
}

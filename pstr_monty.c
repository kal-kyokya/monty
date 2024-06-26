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
	(void)count;

	current = *h;
	if (current == NULL)
		printf("\n");
	else
	{
		while (current != NULL && current->n != 0)
		{
			if (current->n > 127 || current->n < 0)
				break;
			printf("%c", current->n);
			current = current->next;
		}
		printf("\n");
	}
}

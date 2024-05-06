#include "monty.h"

/**
 * mswap - swaps the top two elements of the stack
 * @h: head
 * @count: line number
 *
 * Return: nothing.
 */
void mswap(stack_t **h, unsigned int count)
{
	stack_t *temp;

	if ((*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		fclose(variable.file);
		free(variable.text);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	*h = temp->next;
	temp->next = (*h)->next;
	(*h)->prev = NULL;
	(*h)->next = temp;
	temp->prev = *h;
}

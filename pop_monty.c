#include "monty.h"

/**
 * mpop - removes the top element of the stack
 * @h: head
 * @count: line number
 *
 * Return: nothing.
 */
void mpop(stack_t **h, unsigned int count)
{
	stack_t *temp;

	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		fclose(variable.file);
		free(variable.text);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	*h = temp->next;
	free(temp);
}

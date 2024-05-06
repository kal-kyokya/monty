#include "monty.h"

/**
 * mpint - prints the value at the top of the stack
 * @h: head
 * @count: line number
 *
 * Return: nothing.
 */
void mpint(stack_t **h, unsigned int count)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(variable.file);
		free(variable.text);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}

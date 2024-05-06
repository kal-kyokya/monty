#include "monty.h"

/**
 * madd - adds the top two elements of the stack
 * @h: head
 * @count: line number
 *
 * Return: nothing.
 */
void madd(stack_t **h, unsigned int count)
{
	stack_t *temp;
	int sum;
	
	if ((*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", count);
		fclose(variable.file);
		free(variable.text);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	temp->next->n += temp->n;
	*h = temp->next;
	(*h)->prev = NULL;
	free(temp);
}

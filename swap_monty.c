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
	int arg_len = 0, swap_value;

	temp = *h;
	while (temp)
	{
		temp = temp->next;
		arg_len++;
	}
	if (arg_len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		fclose(variable.file);
		free(variable.text);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	swap_value = temp->n;
	temp->n = temp->next->n;
	temp->next->n = swap_value;
}

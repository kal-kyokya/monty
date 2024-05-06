#include "monty.h"

/**
 * mmod - Modides the top 2 stack and pop the top one.
 * @h: Address of the pointer to the top of the stack.
 * @count: Line number from file.
 *
 * Return: Nothing.
 **/
void mmod(stack_t **h, unsigned int count)
{
	stack_t *top;

	top = *h;
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", count);
		free_stack(*h);
		free(variable.text);
		fclose(variable.file);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", count);
		free_stack(*h);
		free(variable.text);
		fclose(variable.file);
		exit(EXIT_FAILURE);
	}
	top->next->n %= top->n;
	*h = top->next;
	top->prev = NULL;
	free(top);
}

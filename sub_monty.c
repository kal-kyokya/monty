#include "monty.h"

/**
 * msub - Substracts the top 2 stack and pop the top one.
 * @h: Address of the pointer to the top of the stack.
 * @line: Line number from file.
 *
 * Return: Nothing.
 **/
void msub(stack_t **h, unsigned int line)
{
	stack_t *top;

	top = *h;
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short", line);
		free_stack(*h);
		free(variable.text);
		fclose(variable.file);
		exit(EXIT_FAILURE);
	}
	top->next->n -= top->n;
	*h = top->next;
	top->prev = NULL;
	free(top);
}

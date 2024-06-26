#include "monty.h"

/**
 * mpchar - prints the char at the top of the stack
 * @h: head
 * @count: line number
 *
 * Return: nothing.
 */
void mpchar(stack_t **h, unsigned int count)
{
	stack_t *top;

	top = *h;
	if (top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", count);
		fclose(variable.file);
		free(variable.text);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", count);
		fclose(variable.file);
		free(variable.text);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}

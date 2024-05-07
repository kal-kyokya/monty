#include "monty.h"

/**
 * mqueue - Sets the insertion mode of monty as a queue.
 * @h: Address of the pointer to the top of the stack.
 * @count: Line number.
 *
 * Return: Nothing.
 */
void mqueue(stack_t **h, unsigned int count)
{
	(void)count;
	(void)h;

	variable.flag = 1;
}

/**
 * mstack - Sets the insertion mode of monty as a stack.
 * @h: Address of the pointer to the top of the stack.
 * @count: Line number.
 *
 * Return: Nothing.
 */
void mstack(stack_t **h, unsigned int count)
{
	(void)count;
	(void)h;

	variable.flag = 0;
}

#include "monty.h"

/**
 * mpush - pushes an element to the stack
 * @h: head
 * @count: line count or line number
 *
 * Return: nothing.
 */
void mpush(stack_t **h, unsigned int count)
{
	int i = 0, num;

	if (!variable.argvalue)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(variable.file);
		free(variable.text);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	if (variable.argvalue[0] == '-')
		i++;
	while (variable.argvalue[i] != '\0')
	{
		if (variable.argvalue[i] > '9' || variable.argvalue[i] < '0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(variable.file);
			free(variable.text);
			free_stack(*h);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	num = atoi(variable.argvalue);
	if (variable.flag == 0)
		add_node(h, num);
	else
		add_node_end(h, num);
}

#include "monty.h"

/**
 * exec_monty - execute monty texts
 * @stack: head of a stack or linked list
 * @count: line number counter
 * @file: pointer to the file
 * @text: line of code to be executed
 *
 * Return: 0 success.
 */

int exec_monty(char *text, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t compare[] = {
		{"push", mpush},
		{"pall", mpall},
		{"pint", mpint},
		{"pop", mpop},
		{"swap", mswap},
		{"add", madd},
		{"nop", mnop},
		{NULL, NULL}
	};
	char *code;
	unsigned int i = 0;

	code = strtok(text, " \n\t");
	if (code && code[0] == '#')
		return (0);
	variable.argvalue = strtok(NULL, " \n\t");
	while (compare[i].opcode && code)
	{
		if (strcmp(code, compare[i].opcode) == 0)
		{
			compare[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (code && compare[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unkown instruction %s\n", count, code);
		fclose(file);
		free(text);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

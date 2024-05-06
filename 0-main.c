#define _GNU_SOURCE
#include "monty.h"

variable_t variable = {NULL, NULL, NULL, 0};

/**
 * main - Interprets the Monty language
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 success.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t read = 1;
	char *text = NULL;
	unsigned int count = 0;

	file = check_monty(argc, argv);
	while ((read = getline(&text, &len, file)) != -1)
	{
		variable.text = text;
		count++;
		if (read > 0)
		{
			exec_monty(text, &stack, count, file);
		}
	}
	free_stack(stack);
	free(text);
	fclose(file);

	return (0);
}

FILE *check_monty(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	variable.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file);
}


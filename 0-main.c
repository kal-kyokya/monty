#include "monty.h"

int push_value;

/**
 * push - Adds an element to the stack.
 * @top: Address of the pointer to last added node to the DLL.
 * @l_num: Integer referring the nth line in file.
 *
 * Return: Nothing.
 */
void push(stack_t **top, unsigned int l_num)
{
	stack_t *new_stack;

	if (top == NULL)
	{
		dprintf(2, "Error:Line %d: Couldn't find top stack.\n", l_num);
		exit(EXIT_FAILURE);
	}
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		dprintf(2, "Error:Line %d: Failed to malloc new stack.\n", l_num);
		exit(EXIT_FAILURE);
	}
	new_stack->value = push_value;
	new_stack->prev = NULL;
	if (*top == NULL)
	{
		new_stack->next = NULL;
		*top = new_stack;
	}
	else
	{
		new_stack->next = *top;
		(*top)->prev = new_stack;
		*top = new_stack;
	}
}

/**
 * pall - Prints all elements found on the stack.
 * @top: Address of the pointer to last added node to DLL.
 * @l_num: Integer referring the nth line in file.
 *
 * Return: Nothing.
 */
void pall(stack_t **top, unsigned int l_num)
{
	stack_t current;

	current = *top;
	if (top == NULL)
	{
		dprintf(2, "Error:Line %d: Couldn't find top stack.\n", l_num);
		exit(EXIT_FAILURE);
	}
	while (current != NULL)
	{
		print("%d\n", current->value);
		current = current->next;
	}
}

/**
 * main - Entry point to the monty program.
 * @argc: Number of command line arguments.
 * @argv: List of command line arguments.
 *
 * Return: 0 if programs runs successfully, 1 otherwise.
 */
int main(int argc, char **argv)
{
	int fd, index;
	char read_buffer[1024], line_copy[100], *line, *token;
	unsigned int l_num;
	instruction_t instr[] = {
		{"push", push},
		{"pall", pall}
	};
	stack_t *top;

	top = NULL;
	printf("--------\n");
	l_num = 1;
	index = 0;
	if (argc != 2)
	{
		dprintf(2, "Usage: ./monty <file_name>\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read(fd, read_buffer, 1024);
	printf("sizeof of the file: %ld\n", sizeof(read_buffer));
	printf("strlen of the file: %ld\nL%u: ", strlen(read_buffer), l_num);
	line = strtok(read_buffer, "\n");
	printf("index %d\nLine is: \"%s\"\n", index, line);
	strcpy(line_copy, line);
	printf("Line_copy is (%s)\n", line_copy);
	token = strtok(line_copy, " ");
	printf("From line_copy: Token is \"%s\"\n", token);
	while (index < 2)
	{
		if (!strcmp(token, instr[index].opcode))
		{
			token = strtok(NULL, " ");
			printf("Followed by \"%s\"\n", token);
			if (!atoi(token) && strcmp(token, "0"))
				printf("\"%s\" is not an integer.\n", token);
			else
			{
				push_value = (atoi(token));
				printf("push_value is: %d\n", push_value);
				instr[index].f(&top, l_num);
			}
			break;
		}
		index++;
	}
	if (index >= 2)
		printf("Invalid command: %s.\n", token);

	close(fd);
	return (0);
}

#include "monty.h"

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
		fprintf(stderr, "Error:Line %d: Couldn't find top stack.\n", l_num);
		exit(EXIT_FAILURE);
	}
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
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
	stack_t *current;

	current = *top;
	if (top == NULL)
	{
		fprintf(stderr, "Error:Line %d: Couldn't find top stack.\n", l_num);
		exit(EXIT_FAILURE);
	}
	while (current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

/**
 * pint - Prints the element at the top of the stack.
 * @top: Address of the pointer to last added node to DLL.
 * @l_num: Integer referring the nth line in file.
 *
 * Return: Nothing.
 */
void pint(stack_t **top, unsigned int l_num)
{
	if (top == NULL)
	{
		fprintf(stderr, "Error:Line %d: Couldn't find top stack.\n", l_num);
		exit(EXIT_FAILURE);
	}
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*top)->value);
}

/**
 * l_check - Checks if an input has the right syntax.
 * @l: String to be parsed in search for opcode.
 * @instr: List of opcodes and their associated functions.
 * @l_n: Number referring the line in file being processed.
 * @t: Address of the pointer to the top of the stack.
 *
 * Return: Nothing.
 */
void l_check(char *l, instruction_t instr[], unsigned int l_n, stack_t **t)
{
	char *token;
	int l_index, index;

	l_index = index = 0;
	if (l[l_index] == '\0')
		return;
	token = strtok(l, " ");
	if (token == NULL)
	{
		fprintf(stderr, "\nERROR:L%d: NULL input.\n", l_n);
		exit(EXIT_FAILURE);
	}
	while (index < 3)
	{
		if (!strcmp(token, instr[index].opcode))
		{
			if (index == 0)
			{
				token = strtok(NULL, " ");
				if (!atoi(token) && strcmp(token, "0"))
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", l_n, token);
					exit(EXIT_FAILURE);
				}
				else
					push_value = (atoi(token));
			}
			instr[index].f(t, l_n);
			return;
		}
		index++;
	}
	if (index >= 2)
	{
		printf("L%d: unknown instruction %s\n", l_n, token);
		exit(EXIT_FAILURE);
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
	int fd = open(argv[1], O_RDONLY);
	char read_buffer[1024], *str;
	unsigned int l_num = 1;
	instruction_t instr[] = { {"push", push}, {"pint", pint}, {"pall", pall} };
	stack_t *top = NULL;
	list_t  *new = malloc(sizeof(list_t)), *head = new, *current;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./monty <file_name>\n");
		exit(EXIT_FAILURE);
	}
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	read(fd, read_buffer, 1024);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->str = strtok(read_buffer, "\n");
	new->next = new->prev = NULL;
	while (new->str != NULL)
	{
		str = strtok(NULL, "\n");
		new = add_node_end(&head, str);
	}
	current = head;
	while (current->next != NULL)
	{
		line_check(current->str, instr, l_num++, &top);
		current = current->next;
	}
	free(top);
	free(head);
	close(fd);
	return (0);
}

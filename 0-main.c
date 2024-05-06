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
	printf("\n");
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
	printf("\n");
}

/**
 * line_check - Checks if an input has the right syntax.
 * @line: String to be parsed in search for opcode.
 * @instr: List of opcodes and their associated functions.
 *
 * Return: Nothing.
 */
void line_check(char *line, instruction_t instr[], unsigned int l_num, stack_t **top)
{
	char *token;
	int l_index, index;

	l_index = index = 0;
	if (line[l_index] == '\0')
		return;
	while (line[l_index] == ' ')
	{
		if (line[++l_index] == '\0')
			return;
	}
	token = strtok(line, " ");
	if (token == NULL)
	{
		fprintf(stderr, "\nERROR:L%d: NULL input.\n", l_num);
		exit(EXIT_FAILURE);
	}
	printf("\"%s\"\n", token);
	while (index < 3)
	{
		if (!strcmp(token, instr[index].opcode))
		{
			if (index == 0)
			{
				token = strtok(NULL, " ");
				if (!atoi(token) && strcmp(token, "0"))
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", l_num, token);
					exit(EXIT_FAILURE);
				}
				else
					push_value = (atoi(token));
			}
			instr[index].f(top, l_num);
			return;
		}
		index++;
	}
	if (index >= 2)
	{
		printf("L%d: unknown instruction %s\n", l_num, token);
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
	int fd;
	char read_buffer[1024], *str;
	unsigned int l_num;
	instruction_t instr[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall}
	};
	stack_t *top;
	list_t  *head, *new_node, *current;

	l_num = 1;
	top = NULL;
	head = NULL;
	printf("--------\n");
	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./monty <file_name>\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	read(fd, read_buffer, 1024);
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->str = strtok(read_buffer, "\n");
	new_node->next = NULL;
	new_node->prev = NULL;
	head = new_node;
	while (new_node->str != NULL)
	{
		str = strtok(NULL, "\n");
		new_node = add_node_end(&head, str);
	}
	current = head;
	while (current->next != NULL)
	{
		printf("L%d: ", l_num);
		line_check(current->str, instr, l_num, &top);
		l_num++;
		current = current->next;
	}

	free(top);
	free(head);
	close(fd);
	return (0);
}

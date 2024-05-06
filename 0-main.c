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
 * pop - Deletes the element at the top of the stack.
 * @top: Address of the pointer to last added node to DLL.
 * @l_num: Integer referring the nth line in file.
 *
 * Return: Nothing.
 */
void pop(stack_t **top, unsigned int l_num)
{
	stack_t *temp;

	if (top == NULL)
	{
		fprintf(stderr, "Error:Line %d: Couldn't find top stack.\n", l_num);
		exit(EXIT_FAILURE);
	}
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", l_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *top;
		*top = (*top)->next;
		free(temp);
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
	instruction_t instr[] = { {"push", push}, {"pint", pint}, {"pop", pop}, {"pall", pall} };
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
		l_check(current->str, instr, l_num++, &top);
		current = current->next;
	}
	free(top);
	free(head);
	close(fd);
	return (0);
}

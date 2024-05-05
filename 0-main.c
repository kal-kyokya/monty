#include "monty.h"

/**
 * push - Adds an element to the stack.
 * @top: Address of the pointer to last added node to SLL.
 * @line_number: Integer referring the nth line in file.
 *
 * Return: Nothing.
 */
void push(stack_t **top __attribute__ ((unused)), unsigned int line_number __attribute__ ((unused)))
{

}

/**
 * pall - Prints all elements found on the stack.
 * @top: Address of the pointer to last added node to SLL.
 * @line_number: Integer referring the nth line in file.
 *
 * Return: Nothing.
 */
void pall(stack_t **top __attribute__ ((unused)), unsigned int line_number __attribute__ ((unused)))
{

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
			{
				printf("\"%s\" is not an integer.\n", token);
			}
			break;
		}
		index++;
	}

	close(fd);
	return (0);
}

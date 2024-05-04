#include "monty.h"

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
	char read_buffer[1024], *token;
	instruction_t instr[] = {
				{"push", (*push)()},
				{"pall", (*pall)()}
	};
	stack_t *top;
	unsigned int l_num;

	head = NULL;
	index = 0;
	l_num = 1;
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
	printf("strlen of input file is %ld\n", strlen(read_buffer));
	token = strtok(read_buffer, " ");
	switch (token)
	{
		case instr[0].opcode:
			token = strtok(NULL, "\n");
			if (atoi(token))
			{
				instr[0].push(&top, l_num);
				l_num++;
			}
			else
			{
				dprintf(2, "L%u: usage: push integer\n", l_num);
				exit(EXIT_FAILURE);
			}
		case instr[1].opcode:
			instr[1].pall();
	}
	printf("Index is %d\nToken is %s\n", index, token);

	close(fd);
	return (0);
}

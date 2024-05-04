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
	char read_buffer[1024], *line, *token;
	unsigned int l_num;

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
	token = strtok(line, " ");
	printf("Token is \"%s\"\n", token);
	if (!strcmp(token, "push"))
	{
		token = strtok(NULL, " ");
		printf("Followed by \"%s\"\n", token);
		if (!atoi(token) && strcmp(token, "0"))
		{
			printf("\"%s\" is not an integer.\n", token);
		}
	}

	close(fd);
	return (0);
}

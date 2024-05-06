#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int push_value;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @value: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int value;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list_s - Doubly linked list
 * @str: string
 * @next: points to the next node
 * @prev: points to the previous node.
 *
 * Description: Doubly linked list node structure for project
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
	struct list_s *prev;
} list_t;

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer of first node of list_t list
 * @str: String to be included in new node
 *
 * Return: address of the new element or NULL if it fails
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new;
	list_t *current;

	current = *head;
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = str;
	new->next = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;

	return (new);
}

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

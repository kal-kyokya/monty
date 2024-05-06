#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
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
 * struct variable_s - variables to be used
 * @argvalue: value of argument stored
 * @file: pointer to the file
 * @text: content or code on a line
 * @flag: to swap in stack
 * Description: variables to be used through the program
 */
typedef struct variable_s
{
	char *argvalue;
	FILE *file;
	char *text;
	int flag;
} variable_t;

extern variable_t variable;

int main(int argc, char *argv[]);
FILE *check_monty(int argc, char *argv[]);
void mpush(stack_t **h, unsigned int count);
void mpop(stack_t **h, unsigned int count);
void mpall(stack_t **h, unsigned int count);
void mpint(stack_t **h, unsigned int count);
void mswap(stack_t **h, unsigned int count);
void madd(stack_t **h, unsigned int count);
void mnop(stack_t **h, unsigned int count);
void free_stack(stack_t *h);
void add_node_end(stack_t **h, int n);
void add_node(stack_t **h, int n);
int exec_monty(char *text, stack_t **stack, unsigned int count, FILE *file);

#endif /* MONTY_H */

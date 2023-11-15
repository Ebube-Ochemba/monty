#ifndef MONTY_H
#define MONTY_H

/* close, access */
#include <unistd.h>

/* fprintf */
#include <stdio.h>
#include <string.h>

/* malloc, free */
#include <stdlib.h>

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

/********** FUNCTION DECLARATIONS **********/

/*** errors messages ***/
int usage_error(void);
int access_error(char *file);
int f_open_error(char *file);
int not_monty_file(char *file);

#endif

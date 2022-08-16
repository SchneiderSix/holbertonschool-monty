#include "monty.h"

/**
 * push - add int to header of stack
 * @node: head of stack
 * @numbers: number after opcode
 * @line_number: for error in line
 * Return: nothing
 */
void push(stack_t ***node, char *numbers,  unsigned int line_number)
{
	stack_t *nn = NULL;
	int i;

	if (!numbers)
	{
		fprintf(stderr, "L%d: unknown instruction\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; numbers[i] != '\0'; i++)
	{
		if (!isdigit(numbers[i]))
		{
			fprintf(stderr, "L%d: unknown instruction\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	nn = malloc(sizeof(stack_t));
	if (!nn)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	nn->n = atoi(numbers);
	nn->next = NULL;
	nn->prev = NULL;
	if ((**node))
	{
		nn->next = (**node);
		(**node)->prev = nn;
	}
	(**node) = nn;

}

/**
 * pall - print ints from stack
 *
 * @node: head of stack
 * Return: nothing
 */
void pall(stack_t ***node)
{
	stack_t *tmp = **node;

	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * _cases - cases for every opcode
 *
 * @node: head of stack
 * @numbers: number after opcode
 * @opcode: explicit name
 * @line_number: for error in line
 * Return: nothing
 */
void _cases(stack_t **node, char *numbers, char *opcode,
unsigned int line_number)
{
	if (strcmp(opcode, "push"))
	{
		push(&node, numbers, line_number);
	}
	else if (strcmp(opcode, "pall"))
	{
		pall(&node);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction", line_number);
		exit(EXIT_FAILURE);
	}

}

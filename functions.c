#include "monty.h"

/**
 * push - add int to header of stack
 * @node: head of stack
 * @numbers: tokens
 * @line_number: error in line
 * Return: nothing
 */
void push(stack_t **node, char *numbers,  unsigned int line_number)
{
	stack_t *nn = NULL;
	int i;

	if (!numbers)
	{
		printf("L%d: unknown instruction for push", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; numbers[i] != '\0'; i++)
	{
		if (!isdigit(numbers[i]))
		{
			printf("L%d: unknown instruction for push", line_number);
			exit(EXIT_FAILURE);
		}
	}
	nn = malloc(sizeof(stack_t));
	if (!nn)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	nn->n = atoi(numbers);
	nn->next = *node;
	nn->prev = NULL;
	if ((*node) != NULL)
	{
		(*node)->prev = nn;
	}
	(*node) = nn;

}

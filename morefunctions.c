#include "monty.h"

/**
* _pop - removes the top element of the stack
* @stack: stack head
* @line_number: line num
* Return: Void
*/

void _pop(stack_t ***stack, unsigned int line_number)
{
	stack_t *temp;

	temp = **stack;
	if (!stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->next == NULL)
	{
		**stack = NULL;
		return;
	}
	**stack = (**stack)->next;
	(**stack)->prev = NULL;
	free(temp);
}

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
	if (!stack || !**stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (**stack)->next;
	free(**stack);
	**stack = temp;
}


/**
 * node_len - explicit name
 *
 * @node: head
 * Return: len of nodes
 */
size_t node_len(stack_t ***node)
{
	stack_t *tmp;
	unsigned int i = 0;

	tmp = **node;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/**
 * swap - swap data of first and second nodes
 *
 * @node: head 
 * @line_number: line for error
 * Return: nothing 
 */
void swap(stack_t ***node, unsigned int line_number)
{
	int tmp1;
	int tmp2;

	if (node_len(node) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp1 = (**node)->n;
	tmp2 = (**node)->next->n;
	(**node)->n = tmp2;
	(**node)->next->n = tmp1;
}

/**
 * add - adds the top two elements of the stack
 *
 * @node: head
 * @line_number: line for error
 * Return: nothing
 */
void add(stack_t ***node, unsigned int line_number)
{
	int tmp1;
	int tmp2;
	int sum;

	if (node_len(node) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp1 = (**node)->n;
	tmp2 = (**node)->next->n;
	sum = tmp1 + tmp2;
	(**node)->next->n = sum;
	_pop(node, line_number);
}
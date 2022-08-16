#include "monty.h"

/**
 * main - interpreter for monty
 *
 * @argc: arguments count
 * @argv: arguments array
 * Return: error or success
 */
int main(int argc, char *argv[])
{
	FILE *o;
	char *buffer = NULL, *opcode, *numbers;
	stack_t node = NULL;
	unsigned int line_number = 0;

	size_t size 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	o = fopen(argv[1], "r");
	if (!o)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, stdin) != -1)
	{

		opcode = strtok(&buffer, " \t$");
		if (strcmp(opcode, "push") == 0)
		{
			numbers = strtok(NULL, " \t$");
			push(&node, numbers, line_number)

		}
		else
		{
			/*every other opcode less of course op push*/
		}
		line_number++;

	}
	fclose(o);
	free(buffer);
	exit(99);

}

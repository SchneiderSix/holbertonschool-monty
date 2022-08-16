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
	stack_t *node = NULL;
	unsigned int line_number = 0;
	size_t size = 0;
	size_t rd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	o = fopen(argv[1], "r");
	if (!o)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((rd = getline(&buffer, &size, o)) != -1)
	{
		line_number++;
		opcode = strtok(buffer, " \t\n\r");
		if (!opcode)
			continue;
		numbers = strtok(NULL, " \t\n\r");
		_cases(&node, numbers, opcode, line_number);
	}
	free(buffer), fclose(o);
	return (EXIT_SUCCESS);

}

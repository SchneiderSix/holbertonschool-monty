#include "monty.h"

int main (int argc, char *argv[])
{
	FILE *o;
	char *buffer = NULL, *token;
	size_t size 0;
	stack_t node;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	o = fopen(argv[1], "r");
	if (!o)
	{
		fprintf(stderr, "Error: Can't open file %p", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, stdin) != -1)
	{
		token = strtok(&buffer, "\n");
		process(&buffer, node, line_number);
		line_number++;
	}
	fclose(o);
	free(buffer);
	exit(99);

}
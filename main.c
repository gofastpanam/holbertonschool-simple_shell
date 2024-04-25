#include "main.h"

/**
* main - Entry point of the shell program
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
* Return: 0 on success, 1 on failure
*/
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		if (isatty(STDIN_FILENO))
		{
			interactive_mode();
		}
		else
		{
			non_interactive_mode();
		}
	}
	else
	{
		fprintf(stderr, "Usage: %s [command]\n", argv[0]);
		return (1);
	}
	return (0);
}

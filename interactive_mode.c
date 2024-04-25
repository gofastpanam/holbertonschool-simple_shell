#include "main.h"

/**
* interactive_mode - Run the shell in interactive mode
*/
void interactive_mode(void)
{
	char *input = NULL;

	size_t input_size = 0;
	ssize_t bytes_read;

	while (1)
	{
		size_t i;

		display_prompt();
		bytes_read = getline(&input, &input_size, stdin);
		if (bytes_read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(input);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("Error");
				free(input);
				exit(EXIT_FAILURE);
			}
		}
		for (i = 0; i < (size_t)bytes_read; i++)
		{
			if (input[i] == '\n')
			{
				input[i] = '\0';
				break;
			}
		}
		if (run_command(input) == -1)
		{
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	free(input);
}

/**
* non_interactive_mode - Run the shell in non-interactive mode
*/
void non_interactive_mode(void)
{
	char *input = NULL;

	size_t input_size = 0;
	ssize_t bytes_read;

	while ((bytes_read = getline(&input, &input_size, stdin)) != -1)
	{
		size_t i;

		for (i = 0; i < (size_t)bytes_read; i++)
		{
			if (input[i] == '\n')
			{
				input[i] = '\0';
				break;
			}
		}
		if (run_command(input) == -1)
		{
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	free(input);
}

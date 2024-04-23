#include "shell.h"

/**
* display_prompt - Display the command prompt.
*/
void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

/**
* run_command - Execute the command entered by the user.
* @input: The command to execute.
*
* Return: 0 on success, -1 on failure.
*/
int run_command(char *input)
{
	pid_t pid;
	int status;

	char *argv[64];

	char *token;

	int argc = 0;

	token = strtok(input, " ");
	while (token != NULL && argc < 63)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error");
			return (-1);
		}
	}
	return (0);
}

/**
* main - Entry point for the shell program.
*
* Return: Always returns 0 on success.
*/
int main(void)
{
	char input[1024];

	while (1)
	{
		display_prompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		input[strcspn(input, "\n")] = '\0';
		if (run_command(input) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

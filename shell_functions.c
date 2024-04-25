#include "main.h"

/**
* display_prompt - Display the shell prompt
*/
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("#cisfun$ ");
		fflush(stdout);
	}
}

/**
* run_command - Execute a shell command
* @input: The command to execute
* Return: 0 on success, -1 on failure
*/
int run_command(char *input)
{
	pid_t pid;
	int status;

	char *argv[64];

	char *token;

	int argc = 0;

	char path[256];

	token = strtok(input, " ");
	while (token != NULL && argc < 63)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;
	if (argc == 0)
	{
		return (0);
	}
	if (argc > 0 && strcmp(argv[0], "exit") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	else if (pid == 0)
	{
		if (getenv("PATH") == NULL)
		{
			strcpy(path, "/bin:/usr/bin");
			setenv("PATH", path, 1);
		}
		execvp(argv[0], argv);
		perror("Error");
		exit(EXIT_FAILURE);
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

#include "shell.h"

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
* interactive_mode - Run the shell in interactive mode
*/
void interactive_mode(void)
{
	char input[1024];

	char *newline_pos;

	while (1)
	{
		display_prompt();
		if (scanf("%[^\n]%*c", input) == EOF)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		newline_pos = strchr(input, '\n');

		if (newline_pos != NULL)
		{
			*newline_pos = '\0';
		}

		if (run_command(input) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
}

/**
* non_interactive_mode - Run the shell in non-interactive mode
* @command: The command to execute
*/
void non_interactive_mode(void)
{
	char input[1024];

	while (fgets(input, sizeof(input), stdin) != NULL)
	{
		input[strcspn(input, "\n")] = '\0';
		if (run_command(input) == -1)
		{
			exit(EXIT_FAILURE);
		}
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
	if (argc > 0 && strcmp(argv[0], "exit") == 0)
	{
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
			interactive_mode();
		else
			non_interactive_mode();
	}
	else
	{
		fprintf(stderr, "Usage: %s [command]\n", argv[0]);
		return (1);
	}
	return (0);
}

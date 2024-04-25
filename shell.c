#include "shell.h"

int run_command(char *input);

/*
* display_prompt - Display the command prompt.
*/
void display_prompt(void)
{
    printf("#cisfun$ ");
    fflush(stdout);
}
/*
* interactive_mode - Enter interactive mode for the shell.
*/
void interactive_mode(void)
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
                exit(EXIT_SUCCESS);
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
}
/*
* non_interactive_mode - Enter non-interactive mode for the shell.
* @command: The command to execute.
*/
void non_interactive_mode(char *command)
{
    if (run_command(command) == -1)
    {
        exit(EXIT_FAILURE);
    }
}
/*
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
    char path[256];
        
    token = strtok(input, " ");
    while (token != NULL && argc < 63)
    {
            argv[argc++] = token;
            token = strtok(NULL, " ");
    }
    argv[argc] = NULL;
    
    if (argc > 0 && strcmp(argv[0], "exit") == 0)
        exit(EXIT_SUCCESS);
        
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
/*
* main - Entry point for the shell program.
* @argc: The number of command-line arguments.
* @argv: An array containing the command-line arguments.
*
* Return: Always returns 0 on success.
*/
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        interactive_mode();
    }
    else if (argc == 2)
    {
        non_interactive_mode(argv[1]);
    }
    else
    {
        fprintf(stderr, "Usage: %s [command]\n", argv[0]);
        return (1);
    }
    return (0);
}
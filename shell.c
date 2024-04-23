#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;

void display_prompt(void)
{
    if (isatty(STDIN_FILENO))
    {
        printf("cisfun$ ");
        fflush(stdout);
    }
}

char *find_command(char *args)
{
    int count = 0;
    const char *path[] = {"/bin", "/usr/bin", NULL};
    static char full_path[1024];
    

        if (access(args, X_OK) == 0)
        {
                return strdup(args);

        }

    printf("Searching for command: %s\n", args);
    while (path[count] != NULL)
    {
        sprintf(full_path, "%s/%s", path[count], args);

        full_path[(sizeof(full_path) - 1)] = '\0';
        printf("Checking path: %s\n", full_path);
        
        if (access(full_path, X_OK) == 0)
        {
            return strdup(full_path);
        }            count++;

    }
    return NULL;
}

int run_command(char *input)
{
    pid_t pid;
    int status;
    char *argv[64];
    char *token;
    int argc = 0;
    token = find_command(input);
    token = strtok(input, " :");
    while (token != NULL && argc < 63) 
    {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    pid = fork();
    if (pid == -1)
    {
        perror("error");
        return -1;
    } 
    else if (pid == 0)
    {
        execve(argv[0], argv, environ);
        perror("error");
        exit(EXIT_FAILURE);
    } 
           

    else
        waitpid(pid, &status, 0);
    token = strtok(NULL, ":");
    return 0;
}


int main(void)
{
    char *input = NULL;
    size_t input_size = 0;
    ssize_t characters_read;
    while (1)
    {
        display_prompt();
        characters_read = getline(&input, &input_size, stdin);
        if (characters_read == -1)
        {
            if (feof(stdin))
            {
                printf("\n");
                break;
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }
        input[strcspn(input, "\n")] = '\0';
        
        if (run_command(input) == -1)
            fprintf(stderr, "Failed to execute command: %s\n", input);
        else
            run_command(input);
    }
    free(input);
    return 0;
}
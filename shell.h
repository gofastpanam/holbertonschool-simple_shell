#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/* Déclaration externe pour accéder aux variables d'environnement du système*/
extern char **environ;

void display_prompt(void);
void interactive_mode(void);
void non_interactive_mode(void);
int run_command(char *input);
#endif /* SIMPLE_SHELL_H */
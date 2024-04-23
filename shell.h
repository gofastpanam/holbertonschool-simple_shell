#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
// Inclure les bibliothèques nécessaires pour les fonctionnalités du shell
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
// Déclaration externe pour accéder aux variables d'environnement du système
extern char **environ;
// Prototypes de fonctions pour les diverses fonctionnalités du shell
void display_prompt(void);
char *read_line(void);
char *find_in_path(char *cmd);
void execute_command(char *command);
#endif /* SIMPLE_SHELL_H */
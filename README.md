# C - Simple Shell

## Description of the project
Write a simple UNIX command interpreter.

## Evironment
- Operating system : Ubuntu 20.04 LTS
- Compiler : gcc 9.3.0
- GCC options : Wall -Werror -Wextra -pedantic -std=gnu89

## Project specifitacation
- No more than 5 functions per file.
- All your header files should be include guarded.
- There is one project repository per group.
- Your shell should not have any memory leaks.
- Use system calls only when you need to.

## Exemples
- Example of error with sh:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

- Same error with your program hsh:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## Man page
```
.TH man 3 "18 april 2024" "simple_shell man page"
```
.SH NAME
hsh - Simple Shell: command line interpreter

.SH SYNOPSIS FOR INTERACTIVE MODE
Type ./hsh to show prompt Command: [command] [options]

.SH SYNOPSIS NON INTERACTIVE 
echo "[command] [options]" | ./hsh

.SH DESCRIPTION
simple_shell (compiled as hsh) is a recreation of the sh command interpreter ( A shell is a command language 
interpreter that executes commands read from the standard input or from a file.), made using C language.
This version can execute any comman that points to an executable file, files with the full direction
(for instance "/bin/ls") and files that can be found in the PATH environment variable (for instance "ls").
All the execution that are not built-ins are made using the execve C function.

.SH USER INPUT
Once a user inputs a command and hits enter, the shell performs the following actions:

.br
1. Displaying the prompt.
.br
2. Reading the command.
.br
3. Command interpretation.
.br
4. Command execution.
.br
5. Waiting for the command to finish.

.SH SEARCH FOR COMMAND
When locating a command, the shell looks for a built-in command by that name.
If a built-in command is not found, the shell searches for the command in the PATH.

.SH EXECUTE COMMAND
Commands are executed in a child process of the main process.

.SH EXAMPLES

interactive mode :
```
root@LAPTOP-DCFNNBS8:~/holbertonschool-simple_shell# ./shell
#cisfun$ ls
AUTHORS  README.md  man_1_simple_shell  shell  shell.c  shell.h  simple_shell_flowchart.png
#cisfun$ 
```
error situation :
```
root@LAPTOP-DCFNNBS8:~/holbertonschool-simple_shell# ./shell
#cisfun$ lss
Error: No such file or directory
#cisfun$ 
```
non interactive mode :
```
root@LAPTOP-DCFNNBS8:~/holbertonschool-simple_shell# echo "/bin/ls" | ./shell
AUTHORS  README.md  man_1_simple_shell  shell  shell.c  shell.h  simple_shell_flowchart.png
root@LAPTOP-DCFNNBS8:~/holbertonschool-simple_shell# 
```
.SH BUILT-IN
This version includes 2 built-ins (functions that are not found on PATH).
env : built-in prints all the environment variables. 
exit : ends the shell.

.SH RETURN VALUE
0 if success and 1 if error.

.SH Author
```

## Flowchart 
![Flowchart](https://github.com/gofastpanam/holbertonschool-simple_shell/blob/main/simple_shell_flowchart.png)

Created by : 
- [Anthony Cointre](https://github.com/AnthonyCointre/)
- [Benjamin Jacob](https://github.com/gofastpanam/)
- [Enzo De Freitas](https://github.com/psychohight/)
# C - Simple Shell

## Description
Write a simple UNIX command interpreter.

## Project specification
- No more than 5 functions per file.
- All your header files should be include guarded.
- There is one project repository per group.
- Your shell should not have any memory leaks.
- Use system calls only when you need to.

## Fonctionnalités
- Execution of built-in system commands (such as cd, pwd, exit).
- Execution of external commands using execvp.
- Handling of input/output redirection (>, <, >>).
- Handling of pipes (|) for redirecting the output of one command to the input of another.
- Support for termination signals (Ctrl+C).


## Exemples d'utilisation
- Running an external command: ($ls -l)
- Using input/output redirection: ($cat file.txt > new_file)
- Using pipes to connect commands: ($ cat file.txt | grep keyword)

## Man page

## Flowchart 
![Flowchart](https://github.com/gofastpanam/holbertonschool-simple_shell/blob/main/simple_shell_flowchart.png)

Created by : 
- [Enzo De Freitas] (https://github.com/psychohight/)
- [Anthony Cointre] (https://github.com/AnthonyCointre/)
- [Benjamin Jacob] (https://github.com/gofastpanam/)

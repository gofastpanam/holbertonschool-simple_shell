# C - Simple Shell

## Description
A simple shell is a command line interpreter; it is a computer program that provides a user interface to access certain operating system services.

## Project specification
- No more than 5 functions per file.
- All your header files should be include guarded.
- There is one project repository per group.
- Your shell should not have any memory leaks.
- Use system calls only when you need to.

## Fonctionnalités
- Execution of built-in system commands such as 
    + cd
    + pwd
    + ls 
    + exit
- Execution of external commands using execvp.
- Handling of input/output redirection (>, <, >>).
- Handling of pipes (|) for redirecting the output of one command to the input of another.
- Support for termination signals **Ctrl+C**.

## Exemples d'utilisation
- Running an external command: ($ls -l)
- Using input/output redirection: ($cat file.txt > new_file)
- Using pipes to connect commands: ($ cat file.txt | grep keyword)

## Man page
The man page is a file wich explains in detail how Simple Shell works.
```
$ man ./man_1_simple_shell
```

## Flowchart 
![Flowchart](https://github.com/gofastpanam/holbertonschool-simple_shell/blob/main/simple_shell_flowchart.png)

Created by : 
- [Enzo De Freitas] (https://github.com/psychohight/)
- [Anthony Cointre] (https://github.com/AnthonyCointre/)
- [Benjamin Jacob] (https://github.com/gofastpanam/)

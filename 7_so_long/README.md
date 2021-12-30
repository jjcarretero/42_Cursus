# pipex

*Go dance salsa somewhere.*

![125/100 score](./solong_success.png)

This project aims to make you understand a bit deeper two concepts that you already know: the redirections and the pipes. It is an introduction project.

## Statement

Your objective is to code the Pipex program.

It should be executed in this way:

> $> ./pipex file1 cmd1 cmd2 file2

Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters.

The execution of the pipex program should do the same as the next shell command:

> $> < file1 cmd1 | cmd2 > file2

#### For bonus:

Handle multiple pipes :

> $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

Must be equivalent to :

> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2


Support « and » when the first parameter is "here_doc"

> $> ./pipex here_doc LIMITER cmd cmd1 file

Must be equivalent to:

> cmd << LIMITER | cmd1 >> file

##

Enjoy!

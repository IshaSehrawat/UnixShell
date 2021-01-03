# UnixShell
I implemented a shell which allows five internal commands and five external commands. 
Following two points are the implementation details:
1) For the internal commands, I used some of the C library functions. The internal commands have flag values as well that are handled and will warn the user in case of a wrong input. I implemented --help as a flag for most of the commands which shows the user manpage for the command specified. All the internal commands are present in the same file as the main shell.
2) However, for the external commands, they cannot be defined in the same program as the internal commands, so I created a new process using fork() to call them. The child process runs the external file or we can say the eternal command and the parent process is running the main shell, so the parent process has to wait for the child process to finish its execution and give the rThe waitpid() took the process id of the process it has to wait for as an argument, hence the parent process waits until the child process finishesesult, so I used the waitpid().  its execution. This is repeated for all the external commands. Some external commands also require inputs from the parent process, I sent them using the argv string array and thus the child process gets the information from the parent process to do its task.

The wrong inputs are handled and the shell displays a message “Enter valid command” if no matching command is found.

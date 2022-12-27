#include <readline/readline.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <signal.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>


int main()
{
	char *argv[3];
	extern char **environ;
	//redirecting

	int fd = open("hoge.txt", O_WRONLY);
	dup2(fd, 2);

	//argv[0] = "echo";
	//argv[1] = "Hello World";
	//argv[2] = NULL;
	execve ("/bin/echo", argv, environ);
	return (-1);
}
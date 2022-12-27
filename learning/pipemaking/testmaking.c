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
#include <sys/wait.h>

int pipe_fd[2];

void do_child()
{
	char *p = "Hello dad\n";

	sleep(10);
	printf("%s\n", "I'm child");
	close(pipe_fd[0]);
	while (*p != '\0')
	{
		if (write(pipe_fd[1], p, 1) < 0)
		{
			perror("write");
			exit(1);
		}
		p++;
	}
	printf("end children\n");
}

void do_parent()
{
	char c;
	int count, status;

	printf("this is parent\n");
	close(pipe_fd[1]);
	//pipe's input is limited one(one input one output)
	//and input is tied to child(output is tied to parent)
	//pipe is undirectional streaming
	// so read is started after child process
	// (so that print("this is parent") is outputed)?
	printf("this is not waiting child\n");
	while ((count = read(pipe_fd[0], &c, 1)) > 0)
	{
		putchar(c);
	}
	if (count < 0)
	{
		perror("read");
		exit(1);
	}
	printf("this is waiting child\n");
	// if (wait(&status) < 0) 
	// {
	// 	perror("wait");
	// 	exit(1);
	// }
	printf("end parent\n");
}

int main()
{
	//first, make pipe in main()
	//next, fork(), then make a pipe shared by main and forked
	//lust, close main's input and fork's input

	//f
	int child; //fork process's PID

	printf("here is not made fork, so one time implement\n"); 
	if (pipe(pipe_fd) < 0)
	{
		perror("pipe");
		exit(1);
	} //pipe made
	if ((child = fork()) < 0)
	{
		perror("fork");
		exit(1);
	} //child process made, made common pipe
	printf("child num is %d\n", child);
	if (child)
		do_parent();
	else
		do_child();
}


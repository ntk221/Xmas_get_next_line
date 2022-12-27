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

//pipe() make pipe 
//[1] is input
//[0] is output
int pfd[9][2]

//https://keiorogiken.wordpress.com/2017/12/15/%E3%82%B7%E3%82%A7%E3%83%AB%E3%81%AE%E5%A4%9A%E6%AE%B5%E3%83%91%E3%82%A4%E3%83%97%E3%82%92%E8%87%AA%E4%BD%9C%E3%81%97%E3%81%A6%E3%81%BF%E3%82%8B/
int main()
{
	char *argv = {"ls", "|", "head", "|", "wc", NULL}
	// ls | head | wc 
	int i;
	int pipe_locate = [10];
	int pipe_count = 0;
	pipe_locate[0] = -1;

	for (i = 0; argv[i] != NULL; i++)
	{
		if (strcmp(argv[i], "|") == 0)
		{
			pipe_count++;
			pipe_locate[pipe_count] = i;
			argv[i] = NULL;
			//execvp is see the null is end of CMD
			//we only use execv so this must change 
		}
	}
	if (pipe_count == 0) // if no pipe, argv[0] (= some CMD) is actived
	{
		if (fork() == 0) //child
		{
			execvp(argv[0], argv);
			exit(0);
		}else{ //parent
			int status;
			wait(&status);
		} //parent is wating child's CMD action, and end it, exit()
	}
	//lot pipe's function
	for (i = 0; i < pipe_count + 1 && pipe_count != 0; i++)
	{
		if (i != pipe_count)
		{
			pipe(pfd[i]);// if is not last command, make pipe. if 2's pipe, pfd[1][0] =  output pfd[1][1] = input
		}
		if (fork() == 0)// child process
		{
			if (i == 0)//first command
			{
				dup2(pfd[i][1], 1);// first command is wanted to input pipe[1] (= pipe's input), so used dup2
				close(pfd[i][0]);
				close(pfd[i][1]);// why close..?
			}
			else if (i == pipe_count)// last CMD
			{
				dup2(pfd[i - 1][0], 0);// this is last, so output is stdOUT, but argment is input by before pipe, so close pfd[last][1]
				close(pfd[i - 1][0]);//why close..?
				close(pfd[i - 1][1]);
			}
			else//middle
			{
				dup2(pfd[i - 1][0], 0);
				dup2(pfd[i][1], 1);
				close(pfd[i - 1][0]);
				close(pfd[i - 1][1]);
				close(pfd[i][0]);
				close(pfd[i][1]);
			}
			execvp(argv[pipe_locate[i] + 1], argv + pipe_locate[i] + 1);
			exit(0);
		}
		else if (i > 0)
		{
			close(pfd[i - 1][0]);
			close(pfd[i - 1][1]);
		}
	}
	int status;

	//afterall wait child process
    for (i = 0; i < pipe_count + 1; i++) {
        wait(&status);
    }
    return 0;
}
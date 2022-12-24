#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// void command_separate(char *command)
// {
    
// }

int main(void)
{
    char *command;
    int     flag;

    command = (char *)malloc(sizeof(char) * 100);
    //write(1, "-->", 4);
    while(1)
    {
        write(STDOUT_FILENO, "-->", 4);
        flag = read(STDIN_FILENO, command, 100);
        printf("%s\n", command);
        bzero((void *)command, 100);
        if (flag == -1)
            exit (1);
    }
    return (0);
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char *command;

    command = (char *)malloc(sizeof(char) * 100);
    //write(1, "-->", 4);
    while(1)
    {
        write(STDOUT_FILENO, "-->", 4);
        read(STDIN_FILENO, command, 100);
    }
    return (0);
}

#include "../include/minishell.h"

// char *command_separator(int command_num, char **command)
// {
//     int num;
//     char *all_command;

//     num = 1;
//     while(num != command_num)
//     {

//     }
// }

int main(int argc, char **arg)
{
    char    *command;
    int     i;
    int     shitcounter;

    if (argc == 1)
        return ;
    command = arg[2];
    shitcounter = 0;
    while (command[i] != '\0')
    {
        while (shitcounter <= 7)
        {
            if ((command[i] >> shitcounter) & 000000001)
                kill((pid_t)ft_atoi(av[1]), SIGUSR1);
            else
                kill((pid_t)ft_atoi(av[1]), SIGUSR2);
            shitcounter++;
            usleep(1000);
        }
        i++;
    }
}

//bit演算
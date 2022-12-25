/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:42:41 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/24 22:20:20 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "include/minishell.h"

void ft_echo(char *echoed) //optionもうけとればいいのでは
{
	size_t	length;
	char	newline;

	newline = '\n';
	length = strlen(echoed);
	write(1, echoed, length);
	write(1, &newline, 1);
}

void command_separate(char *command)
{
    char **command_all;

	// printf("%s\n", command);
    command_all = split(command, ' ');
	printf("-----------------------------------\n");
    printf("%s\n", command_all[0]);
	printf("%s\n", command_all[1]);
    //puts("hoge");
    //cat test.txt => cat / test.txt
	//echo ---
	if (command_all[0] == "echo")
	{
		printf("test\n");
		ft_echo(command_all[1]);
	}
}

int main(void)
{
    char *command;
    int     flag;

    command = (char *)malloc(sizeof(char) * 100);
    while(1)
    {
        write(STDOUT_FILENO, "-->", 4);
        flag = read(STDIN_FILENO, command, 100);
		if (flag == -1)
            exit (1);
        command_separate(command);
        bzero((void *)command, 100);
    }
    return (0);
}

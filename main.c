/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:42:41 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/24 19:30:23 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void command_separate(char *command)
{
    char **command_all;

    command_all = split(command, ' ');
    //cat test.txt => cat / test.txt
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
        // separated = command_separate(command);
        printf("%s\n", command);
        bzero((void *)command, 100);
        if (flag == -1)
            exit (1);
    }
    return (0);
}

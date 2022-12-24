/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:58:28 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/24 20:10:46 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char **split(char *string, char separater)
{
    size_t  position;
    size_t  command_num;
    char    **command_all;
    size_t  each_command_num;
    int     command_position;
    int     i;

    printf("%s\n", string);

    position = 0;
    command_num = 0;
    while (string[position] != '\0')
    {
        if (position != 0 && string[position - 1] == ' ' && string[position] != ' ')
            command_num++;
        else if (position != 0 && string[position - 1] != ' ' && string[position] == ' ')
            command_num++;
        position++;
    }
    command_num = ((command_num + 1) / 2) + 1;
    command_all = (char **)malloc(sizeof(char *) * (command_num + 1));
    position = 0;
    each_command_num = 0;
	command_position = 0;
    while (command_position != command_num)
    {
        while (string[position] == ' ')
            position++;
        while (string[position] != ' ')
        {
            position++;
            each_command_num++;
        }
        position = position - each_command_num;
        command_all[command_position] = (char *)malloc(sizeof(char) * (each_command_num + 1));
        while (string[position] != ' ')
        {
            command_all[command_position][i] = string[position];
            position++;
            i++;
        }
		command_all[command_position][i] = '\0';
        i = 0;
        command_position++;
		each_command_num = 0;
    }
    command_all[command_num] = NULL;
    return (command_all);
}

/*int main()
{
    char *command = " hoge huga";
    char separator = ' ';
    char **command_all;
	int i;

	i = 0;
    command_all = split(command, separator);
	while (i != 3)
	{
		printf("%s\n", command_all[i]);
		i++;
	}
}*/
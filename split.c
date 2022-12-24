/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:58:28 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/24 20:28:14 by satushi          ###   ########.fr       */
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

// int main()
// {
//     char *command = " cat     etc     or     ";
// 	char *command_1 = "h u l l";
//     char separator = ' ';
//     char **command_all;
// 	char **command_all_1;
// 	int i;

// 	i = 0;
//     command_all = split(command, separator);
// 	while (i != 3)
// 	{
// 		//write(1, command_all[i], strlen(command_all[i]));
// 		printf("%s", command_all[i]);
// 		i++;
// 	}
// 	command_all_1 = split(command_1, separator);
// 	i = 0;
// 	while (i != 4)
// 	{
// 		printf("%s", command_all_1[i]);
// 		i++;
// 	}
// }

void	test_split(void)
{
	char	*test1;
	char	**res1;
	char	*test2;
	char	**res2;
	char	*test3;
	char	**res3;
	char	*test4;
	char	**res4;

	test1 = "hoge huga";
	res1 = split(test1, ' ');
	for (int i = 0; i < 2; i++)
	{
		printf("%s \n", res1[i]);
	}
	test2 = " hoge huga"; 
	res2 = split(test2, ' '); // test2 を受け取れていない .... //satushi受け取れる...？
	for (int i = 0; i < 2; i++)
	{
		printf("%s \n", res2[i]);
	}
	test3 = "     h       u         ";
	res3 = split(test3, ' ');
	for (int i = 0; i < 2; i++)
	{
		printf("%s \n", res3[i]);
	}
	test4 = "";
	res4 = split(test4, ' ');
	for (int i = 0; i < 0; i++)
	{
		printf("%s \n", res4[i]);
	}
}

int	main(void)
{
	test_split();
    // test_len();
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:42:36 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/24 22:27:58 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/minishell.h"

/*int     len(char *res[])
{
    int len;

    len = 0;
    while(res != NULL)
    {
        res++;
        len++;
    }
    return len;
}

void    test_len(void)
{
    char hoge[3][5] ={"hoge", "huga", "hello"}; 
    len(hoge);
}*/

/*void	test_split(void)
{
	char	*test1;
	char	**res1;
	char	*test2;
	char	**res2;
	char	*test3;
	char	**res3;
	char	*test4;
	char	**res4;
	char	*test5;
	char	**res5;
	char	*test6;
	char	**res6;

	test1 = "hoge huga";
	res1 = split(test1, ' ');
	for (int i = 0; i < 2; i++)
	{
		printf("%s \n", res1[i]);
	}
	test2 = " hoge huga";
	res2 = split(test2, ' ');
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
	test5 = "             ";
	res5 = split(test5, ' ');
	test6 = "ahafoiuwehflaiuh";
	res6 = split(test6, ' ');
	{
		printf("%s \n", res6[0]);
	}
}*/


char	**string_to_split(char *string, int command_num)
{
	char **command_all = (char **)malloc(sizeof(char *) * (command_num + 1));
	size_t	position;
	int 	each_command_num = 0;
	int 	command_position = 0;
	int		i;

	while (command_position != command_num)
    {
        while (string[position] == ' ')
            position++;
        while (string[position] != ' ' && string[position] != '\0')
        {
            position++;
            each_command_num++;
        }
        position = position - each_command_num;
        command_all[command_position] = (char *)malloc(sizeof(char) * (each_command_num + 1));
		// printf("each command num is %d\n", each_command_num);
        while (string[position] != ' ')
        {
            command_all[command_position][i] = string[position];
            position++;
            i++;
        }
		position++;
		command_all[command_position][i] = '\0';
        i = 0;
        command_position++;
		each_command_num = 0;
    }
	command_all[command_num] = NULL;
	return (command_all);
}

void	test_string_to_split(void)
{
	char *string = "echo 12";
	char **res = string_to_split(string, 2);
}


int	main(void)
{
	// test_split();
    // test_len();
	test_string_to_split();
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:42:36 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/25 20:53:03 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/minishell.h"

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
	char	*test5;
	char	**res5;
	char	*test6;
	char	**res6;

	char	*delim = " |";

	test1 = "hoge huga";
	res1 = split(test1, delim);
	for (int i = 0; i < 2; i++)
	{
		printf("%s\n", res1[i]);
	}
	test2 = " hoge huga"; 
	res2 = split(test2, delim);
	for (int i = 0; i < 2; i++)
	{
		printf("%s\n", res2[i]);
	}
	test3 = "     h       u         ";
	res3 = split(test3, delim);
	for (int i = 0; i < 2; i++)
	{
		printf("%s\n", res3[i]);
	}
	test4 = "";
	res4 = split(test4, delim);
	for (int i = 0; i < 0; i++)
	{
		printf("%s \n", res4[i]);
	}
	test5 = "             ";
	res5 = split(test5, delim);
	test6 = "ahafoiuwehflaiuh";
	res6 = split(test6, delim);
	{
		printf("%s \n", res6[0]);
	}

	char *test7 = "t e s t";
	char **res7 = split(test7, delim);
	for(int i = 0; i < 4; i++)
	{
		printf("%s\n", res7[i]);
	}

	char *test8 = "English | Japanese";
	char **res8 = split(test8, delim);
	for(int i = 0; i < 2; i++)
	{
		printf("%s\n", res8[i]);
	}
}

int	main(void)
{
	test_split();
	return (0);
}
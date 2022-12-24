/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:42:36 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/24 20:12:17 by kazuki           ###   ########.fr       */
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

	/*test1 = "hoge huga";
	res1 = split(test1, ' ');
	for (int i = 0; i < 2; i++)
	{
		printf("%s \n", res1[i]);
	}*/
	//test2 = " hoge huga"; 
	//res2 = split(test2, ' '); // test2 を受け取れていない ....
	/*for (int i = 0; i < 2; i++)
	{
		printf("%s \n", res2[i]);
	}*/
	test3 = "     h       u         ";
	res3 = split(test3, ' ');
	for (int i = 0; i < 2; i++)
	{
		printf("%s \n", res3[i]);
	}
	/*test4 = "";
	res4 = split(test4, ' ');
	for (int i = 0; i < 0; i++)
	{
		printf("%s \n", res4[i]);
	}*/
}

int	main(void)
{
	test_split();
    // test_len();
	return (0);
}
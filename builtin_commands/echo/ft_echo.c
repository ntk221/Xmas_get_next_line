/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:11:01 by satushi           #+#    #+#             */
/*   Updated: 2022/12/26 11:04:25 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minishell.h"

void ft_echo_with_newline(char **sub, int arg_f, int arg_l)
{
	size_t	echoed_strlen;
	char	space;
	char	newline;

	space = ' ';
	newline = '\n';
	while (arg_f != arg_l)
	{
		echoed_strlen = strlen(sub[arg_f]);
		write(1, sub[arg_f], echoed_strlen);
		if (arg_f != arg_l - 1)
			write(1, &space, 1);
		arg_f++;
	}
	write(1, &newline, 1);
}

void ft_echo_no_newline(void)
{
	char newline;

	newline = '\n';
	write(1, &newline, 1);
}

void ft_echo(char **inputstring_arrange, int *arrange_position)
{
	int echo_arg_l;
	char *nullstring;

	echo_arg_l = 0;
	nullstring = "(null)";
	if (inputstring_arrange[(*arrange_position) + 1] == nullstring)
		ft_echo_no_newline();
	else
	{
		echo_arg_l = catch_echoargnum(inputstring_arrange, (*arrange_position) + 1);
		ft_echo_with_newline(inputstring_arrange, *arrange_position + 1, echo_arg_l);
		*arrange_position = *arrange_position + echo_arg_l;
	}
}
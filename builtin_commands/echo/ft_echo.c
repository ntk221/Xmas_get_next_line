/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:11:01 by satushi           #+#    #+#             */
/*   Updated: 2022/12/25 21:24:18 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minishell.h"

void ft_echo(char **sub, int arg_f, int arg_l)
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

void ft_echo_withno_newline(void)
{
	char newline;

	newline = '\n';
	write(1, &newline, 1);
}
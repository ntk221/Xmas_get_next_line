/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echos_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:44:00 by satushi           #+#    #+#             */
/*   Updated: 2022/12/26 11:04:04 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../include/minishell.h"

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
} */
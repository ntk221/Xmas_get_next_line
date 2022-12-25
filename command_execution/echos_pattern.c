/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echos_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:44:00 by satushi           #+#    #+#             */
/*   Updated: 2022/12/25 19:19:56 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void echo_branch(char **inputstring_arrange, int *arrange_position)
{
	int echo_arg_l;

	echo_arg_l = 0;
	if (inputstring_arrange[(*arrange_position) + 1] == NULL)
		ft_echo_withno_newline();
	else
	{
		echo_arg_l = catch_echoargnum(inputstring_arrange, (*arrange_position) + 1);
		ft_echo(**inputstring_arrange, *arrange_position + 1, echo_arg_l);
		*arrange_position = *arrange_position + echo_arg_l;
	}
}
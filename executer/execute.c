/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switching_by_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:44:06 by satushi           #+#    #+#             */
/*   Updated: 2022/12/28 11:56:11 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool echo_or_not(char *sub)
{
	int		sublen;
	char	*echo;

	sublen = strlen(sub);
	echo = "echo";
	if (sublen != 4)
		return false;
	while (sublen != 0)
	{
		if (sub[sublen] != echo[sublen])
			return false;
		sublen--;
	}
	return (true);
}

void execute(char **tok_seq, int *tok_pos, int delim_num)//, int separatednum
{
	if (true == echo_or_not(tok_seq[*tok_pos]))
		ft_echo(tok_seq, tok_pos); // echo の 引数の有無を判定して処理に回す
	else
		*tok_pos= *tok_pos + delim_num;
	return ;
}
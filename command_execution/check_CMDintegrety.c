/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_CMDintegrety.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:44:06 by satushi           #+#    #+#             */
/*   Updated: 2022/12/25 19:53:13 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void obtain_commandinfo(char **input_string_all, int *inputstringposition, int separatednum)
{
	if (input_string_all[*inputstringposition] == "echo")
		echo_branch(input_string_all, inputstringposition);
	return ;
}
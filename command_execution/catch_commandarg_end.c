/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_commandarg_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:49:29 by satushi           #+#    #+#             */
/*   Updated: 2022/12/25 19:15:09 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int catch_echoargnum(char **inputstring_arrange, int arrange_position)
{
	while (inputstring_arrange[arrange_position] != NULL)
	{
		//if (inputstring_arrange[arrange_position] == '&' || inputstring_arrange[arrange_position] == '|')
			//return arrange_position;
		//パイプに関しては別途作成
		arrange_position++;	
	}
	return arrange_position;
}
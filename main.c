/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:42:41 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/26 11:04:58 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int main()
{
	char	*command;
	char	**separated;
	int		inputed_string_separetednum;
	int		inputstring_position;

	inputed_string_separetednum = 0;
	inputstring_position = 0;
	while(1)
    {
        command = readline("--> ");
        separated = split(command, ' ');
		while (separated[inputed_string_separetednum] != NULL)
			inputed_string_separetednum++;
		while (separated[inputstring_position] != NULL)
		{
			obtain_commandinfo(separated, &inputstring_position, inputed_string_separetednum);
		}
		inputstring_position = 0;
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:42:41 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/28 11:55:21 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void shell_loop()
{
	char	*command_line;
	char	**tok_seq;
	int		delim_num;
	int		tok_pos;
	
	delim_num = 0;
	tok_pos = 0;
	
	while(1)
    {
        command_line = readline("--> ");
        tok_seq = split(command_line, ' ');
		while (tok_seq[delim_num] != NULL)
			delim_num++;
		while (tok_seq[tok_pos] != NULL)
		{
			execute(tok_seq, &tok_pos, delim_num);
		}

    }
}

int main()
{
	shell_loop();
	// while(1)
    // {
    //     command = readline("--> ");
    //     separated = split(command, ' ');
	// 	while (separated[inputed_string_separetednum] != NULL)
	// 		inputed_string_separetednum++;
	// 	while (separated[inputstring_position] != NULL)
	// 	{
	// 		obtain_commandinfo(separated, &inputstring_position, inputed_string_separetednum);
	// 	}
	// 	inputstring_position = 0;
    // }
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:42:41 by kazuki            #+#    #+#             */
/*   Updated: 2022/12/25 20:01:08 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// void ft_echo(char *echoed) //optionもうけとればいいのでは
// {
// 	size_t	length;
// 	char	newline;

// 	newline = '\n';
// 	length = strlen(echoed);
// 	write(1, echoed, length);
// 	write(1, &newline, 1);
// }

// void command_separate(char *command)
// {
//     char **command_all;

// 	// printf("%s\n", command);
//     command_all = split(command, ' ');
// 	printf("-----------------------------------\n");
//     printf("%s\n", command_all[0]);
// 	printf("%s\n", command_all[1]);
//     //puts("hoge");
//     //cat test.txt => cat / test.txt
// 	//echo ---
// 	if (command_all[0] == "echo")
// 	{
// 		printf("test\n");
// 		ft_echo(command_all[1]);
// 	}
// }

// int main(void)
// {
//     char *command;
//     int     flag;

//     command = (char *)malloc(sizeof(char) * 100);
//     while(1)
//     {
//         write(STDOUT_FILENO, "-->", 4);
//         flag = read(STDIN_FILENO, command, 100);
// 		if (flag == -1)
//             exit (1);
//         command_separate(command);
//         bzero((void *)command, 100);
//     }
//     return (0);
// }

int main()
{
	char	*command;
	char	**separated;
	int i = 0;
	int		inputed_string_separetednum;
	int		inputstring_position;

	inputed_string_separetednum = 0;
	inputstring_position = 0;
	while(1)
    {
        command = readline("--> ");
		// printf("command is %ld\n", strlen(command)); //削除予定　デバック用だったため
        separated = split(command, ' ');
		while (separated[inputed_string_separetednum] != NULL)
			inputed_string_separetednum++;
		while (separated[inputstring_position] != NULL)
		{
			// printf("i is %d\n", i); //削除予定　デバック用だったため
			// printf("%s\n", separated[i]); //削除予定　でバック用だったため
			//relative_echo(separated[i]); //echo以外も確認できるようにobtain_commandinfoに移管
			obtain_commandinfo(separated, &inputstring_position, inputed_string_separetednum);
		}
		inputstring_position = 0;
    }

	// command = "ddd ddd ddd";
	// separated = split(command, ' ');

	// while (separated[i] != NULL)
	// {
	// 	printf("%s\n", separated[i]);
	// 	i++;
	// }

    return (0);
}
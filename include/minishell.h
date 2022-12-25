/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:36:13 by satushi           #+#    #+#             */
/*   Updated: 2022/12/25 19:44:37 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/types.h>
# include <stddef.h>

/* util functions */
int ft_atoi(const char *str);
char **split(char *string, char separater);

/*echo's output function*/
void	ft_echo(char **sub, int arg_f, int arg_l);
void	ft_echo_withno_newline(void);

/*command swaitch'd*/
int		catch_echoargnum(char **inputstring_arrange, int arrange_position);
void	obtain_commandinfo(char **input_string_all, int *inputstringposition, int separatednum);
void	echo_branch(char **inputstring_arrange, int *arrange_position);

/*split*/
char	**split(char *split_sub, char separater);

#endif
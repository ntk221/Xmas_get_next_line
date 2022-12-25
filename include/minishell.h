#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

/* struct for command keep */

// typedef struct s_command_history{
// 	t_commands_history	*command_p;
// 	char				*command;
// 	t_commands_history	*command_n;
// } t_commands_history;


/* util functions */
int ft_atoi(const char *str);
char **split(char *string, char separater);

#endif
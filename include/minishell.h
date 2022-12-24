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

/* util functions */
int ft_atoi(const char *str);
char **split(char *string, char separater);

#endif
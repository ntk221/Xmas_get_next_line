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
#include <readline/readline.h>
#include <readline/history.h>

static size_t get_commands_num(char *str)
{
    size_t  pos;
    size_t  commands_num;

    pos = 0;
    commands_num = 0;
	while (str[pos] == ' ' && str[pos] != '\0')
		pos++;
    while (str[pos] != '\0')
    {
        if (pos != 0 && str[pos - 1] == ' ' && str[pos] != ' ')
            commands_num++;
        pos++;
    }
    return (commands_num + 1);
}
//command num is ok

static size_t get_command_len(char *com_seq, int pos)
{
	size_t command_len;
	
	command_len = 0;
	while(com_seq[pos] != ' ' && com_seq[pos] != '\0')
	{
		pos++;
		command_len++;
	}
	return command_len;
}
//obtain_commandlen is ok

char **split(char *src)
{
	size_t commands_num;
	char **input;
	size_t command_len;
	int pos;
	int j;
	size_t k;

	pos = 0;
	j = 0;
	k = 0;
	commands_num = get_commands_num(src);
	input = (char **)malloc(sizeof(char *) * (commands_num + 1));
	while (src[pos] != '\0')
	{
		while(src[pos] == ' ' && src[pos] != '\0')
			pos++;
		command_len = get_command_len(src, pos);
		input[j] = (char *)malloc(sizeof(char) * (command_len + 1));
		while (command_len != k)
		{
			input[j][k] = src[pos];
			pos++;
			k++;
		}
		input[j][k] = '\0';
		j++;
		k = 0;
	}
	input[j] = NULL;
	return input;
}

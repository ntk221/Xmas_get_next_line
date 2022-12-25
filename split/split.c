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

static size_t spliter(char *string)
{
    size_t  position;
    size_t  command_num;

    position = 0;
    command_num = 0;
	while (string[position] == ' ' && string[position] != '\0')
		position++;
    while (string[position] != '\0')
    {
        if (position != 0 && string[position - 1] == ' ' && string[position] != ' ')
            command_num++;
        position++;
    }
    return (command_num + 1);
}
//command num is ok

static size_t obtain_commandlen(char *commanda_all, int position)
{
	size_t command_len;
	
	command_len = 0;
	while(commanda_all[position] != ' ' && commanda_all[position] != '\0')
	{
		position++;
		command_len++;
	}
	return command_len;
}
//obtain_commandlen is ok

char **split(char *split_sub)
{
	size_t command_num;
	char **input;
	size_t command_len;
	int position;
	int j;
	size_t k;

	position = 0;
	j = 0;
	k = 0;
	command_num = spliter(split_sub);
	input = (char **)malloc(sizeof(char *) * (command_num + 1));
	while (split_sub[position] != '\0')
	{
		while(split_sub[position] == ' ' && split_sub[position] != '\0')
			position++;
		command_len = obtain_commandlen(split_sub, position);
		input[j] = (char *)malloc(sizeof(char) * (command_len + 1));
		while (command_len != k)
		{
			input[j][k] = split_sub[position];
			position++;
			k++;
		}
		input[j][k] = '\0';
		j++;
		k = 0;
	}
	input[j] = NULL;
	return input;
}

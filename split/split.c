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

size_t spliter(char *string, char separater)
{
    size_t  position;
    size_t  command_num;
    char    **command_all;
    int	    each_command_num;
    int     command_position;
    int     i;

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

size_t obtain_commandlen(char *commanda_all, int position)
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

char **split(char *split_sub, char separater)
{
	size_t command_num;
	char **input;
	size_t command_len;
	int position;
	int j;
	int k;

	position = 0;
	j = 0;
	k = 0;
	command_num = spliter(split_sub, separater);
	input = (char **)malloc(sizeof(char *) * (command_num + 1));
	while (split_sub[position] != '\0')
	{
		while(split_sub[position] == ' ' && split_sub[position] != '\0')
			position++;
		command_len = obtain_commandlen(split_sub, position);
		printf("%ld\n", command_len);
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

// void relative_echo(char *sub)
// {
// 	char *echo_string;
// 	int position;

// 	echo_string = "echo";
// 	position = 0;
// 	if (strlen(sub) != 4)
// 	{
// 		printf("false1\n");
// 		return ;
// 	}
// 	while (sub[position] != '\0')
// 	{
// 		printf("%c\n", sub[position]);
// 		if (sub[position] != echo_string[position])
// 		{
// 			printf("false2\n");
// 			return;
// 		}
// 		position++;
// 	}
// 	printf("true\n");
// }

// int main()
// {
// 	char	*command;
// 	char	**separated;
// 	int i = 0;

// 	while(1)
//     {
//         command = readline("--> ");
// 		printf("command is %ld\n", strlen(command));
//         separated = split(command, ' ');
// 		while (separated[i] != NULL)
// 		{
// 			printf("i is %d\n", i);
// 			printf("%s\n", separated[i]);
// 			relative_echo(separated[i]);
// 			i++;
// 		}
// 		i = 0;
//     }

// 	// command = "ddd ddd ddd";
// 	// separated = split(command, ' ');

// 	// while (separated[i] != NULL)
// 	// {
// 	// 	printf("%s\n", separated[i]);
// 	// 	i++;
// 	// }

//     return (0);
// }
#include "../include/minishell.h"



int main(void)
{
    char *src = "echo hoge";
    char **tok_seq = split(src);
    int  tok_pos = 0;
    execute(tok_seq, &tok_pos ,1);
    printf("%d\n", tok_pos);
    return 0;
}
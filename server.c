#include <stdio.h>
#include "minishell.h"

//minitalk的に、サーバーを二つ立てる（受け取り側、送信側）
//送信側が言葉を送信する
//受け取り側が受け取り、解釈
//構造体的に受け取ることで

void	recomponent(int signal)
{
	if (signal == SIGUSR1)
		g_char.last_ch += 00000001 << g_char.bitcounter;
	if (g_char.bitcounter == 7)
	{
		write(0, &g_char.last_ch, 1);
		g_char.bitcounter = 0;
		g_char.last_ch = '\0';
		return ;
	}
	g_char.bitcounter++;
}

int main()
{
    printf("%s\n", "this project is started!");
    printf("%s\n", "------------------------");
    //-------------------------------------//

    signal(SIGUSR1, recomponent);
	signal(SIGUSR2, recomponent);
	g_char.bitcounter = 0;
	g_char.last_ch = '\0';
	ft_printf("PID is %d\n", getpid());
	while (1)
		pause();
	return (0);
}
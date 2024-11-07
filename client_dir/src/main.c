#include "../includes/client.h"

int g_received = 0;
static void	send_signals(char sent,	int pid)
{
	int	i;
	i = 7;
	while(i >= 0)
	{
		if(((sent >> i) & 1 ) == 0)
		{
			kill(pid,SIGUSR2);
		}	
		else
			kill(pid,SIGUSR1);
		pause();
			i--;
	}
}
void print_stat(int sig)
{
	(void)sig;
	ft_printf("received a char\n");
}
void tweek_received(int sig)
{
	(void)sig;
	g_received = 1;
}
int	main(int argc, char **argv)
{
	int	i;

	if(argc != 3)
		return (0);
	i = 0;
	signal(SIGUSR1,&print_stat);
	signal(SIGUSR2,&tweek_received);
	while(argv[2][i])
	{
		send_signals(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
}
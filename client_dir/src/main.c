#include "../includes/client.h"


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
		
		usleep(600);
		i--;
			
	}
}
void print_stat(int sig)
{
	(void)sig;
	ft_printf("received a char\n");
}
int	main(int argc, char **argv)
{
	int	i;

	if(argc != 3)
		return (0);
	i = 0;
	signal(SIGUSR1,&print_stat);
	while(argv[2][i])
	{
		send_signals(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:30:08 by bismail           #+#    #+#             */
/*   Updated: 2024/11/06 10:31:34 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	addone(int sig,siginfo_t *info, void *context)
{
	(void)context;
	static int	offset = -1;
	static char tbd = 0;
	tbd <<= 1;
	if(SIGUSR1 == sig)
		tbd |= 1;
	++offset;
	if(offset == 7)
	{
		ft_putchar_fd(tbd,1);
		offset = -1;
		tbd = 0;
		kill(info->si_pid,SIGUSR1);
	}
}


int	main(void)
{
	struct sigaction sa;
	int pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &addone;
	pid = getpid();
	ft_printf("%d \n", pid);
	sigaction(SIGUSR1, &sa,NULL);
	sigaction(SIGUSR2, &sa,NULL);
	while (1)
	{
		pause();
	}
}

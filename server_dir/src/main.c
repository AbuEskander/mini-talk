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

int			g_handledbits = 0;

static void	tobedisplayed(char *tbd, int *offset)
{
	*tbd <<= 1;
	*tbd |= g_handledbits;
	++*offset;
	if(*offset == 7)
	{
		ft_putchar_fd(*tbd,1);
		*offset = -1;
		*tbd = 0;
	}
}
void	addone(int sig)
{
	(void)sig;
	g_handledbits = 1;
}

void	addzero(int sig)
{
	(void)sig;
	g_handledbits = 0;
}

int	main(void)
{
	int pid = getpid();
	int offset;
	char tbd;
	
	offset = -1;
	tbd = 0;
	ft_printf("%d \n", pid);
	signal(SIGUSR1, &addone);
	signal(SIGUSR2, &addzero);
	while (1)
	{
		pause();
		tobedisplayed(&tbd, &offset);
	}
}

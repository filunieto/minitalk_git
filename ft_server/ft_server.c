/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:03:13 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/30 10:32:23 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"

/*
	1. This function is called each time SIGUSER2 / SIGUSER1 is received.
	1.1. If it receives (SIGUSR1 or 1 )-> c = c | (sig == SIGUSR1)
	 c = 0000 0000 | 0000 0001
	1.2. If receive (SIGUSR2 or 0) -> c = c | (sig != SIGUSR1)
	 c = 0000 0000 | 0000 0000
	2. Only enters at "if(++i == 8)" when i == 8. 
	Even if it does not enter if, it increments i
	3. If the byte is not complete need  to add 1 or 0 to the char as below:
	c = c << 1; shift the bits one position to the left and
	wait for a new signal from the client.
	4. Every 8 signals (byte), a signal will be sent to the client (SIGUSR2);
	and at the end of the string '\0', another signal to finish.(SIGUSR1)
*/

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;
	pid_t					pid_client;

	(void)context;
	if (info->si_pid)
		pid_client = info->si_pid;
	c = c | (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid_client, SIGUSR1);
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(pid_client, SIGUSR2);
	}
	else
		c = c << 1;
}

/*
	1. Print the server pid.
	2. We define a sigation struct, which will take the function
	to be executed when the server receives the signals, i.e.
	receive each bit and transform them into char;
*/

int	main(void)
{
	struct sigaction	s_sigaction;
	pid_t				pid_server;

	pid_server = getpid();
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(pid_server, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}

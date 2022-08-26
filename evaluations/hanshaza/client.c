/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:58:19 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/08/26 17:05:27 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

static void	ft_exit_failure(void)
{
	printf("Run the Client with \"./client SERVER_PID MESSAGE\" \n"); //cambiar por write
	exit (EXIT_FAILURE);
}

//este es parte de de funcion signal() int signal(int signum, void (*funct)(int)); . Siempre preferible a sigaction
static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR2) //recibe la senal del server 
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;
	int		j;

	j = 0;
	while (str[j])
	{
		i = 8;
		c = str[j++];
		//manda los bits de derecha a izquierda o al reves
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1); //senal 1
			else
				kill(pid, SIGUSR2); //senal 0
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2); //SIguser1 == 0. Este es el ultimo envio de '\0'
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]) || !ft_atoi(argv[1])) //escribir mensaje de uso correcto
	{
		ft_exit_failure();
		//return (1);
	}
	ft_putstr_fd("Char (bytes)?? sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Char (bytes)?? received: ", 1);
	signal(SIGUSR2, action); //cliente a la escucha de las senales de confirmacion del server
	signal(SIGUSR1, action);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}

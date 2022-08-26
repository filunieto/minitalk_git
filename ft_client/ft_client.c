/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:07:05 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/26 21:03:22 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"

/*
	Error handling
*/

static void	ft_exit_failure(void)
{
	write(1, "Usage case: \"./client SERVER_PID MESSAGE\" \n", 43);
	exit(EXIT_FAILURE);
}

/*
	Function receives the signals from the server 
	every byte(SIGUSR2), and prints out the total
	when it receives the NULL (SIGUSR1).
*/

static void	action(int signal)
{
	static int bytes_received = 0;

	if (signal == SIGUSR2)
		bytes_received++;
	else
	{
		ft_putnbr_fd(bytes_received, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

/*
	Send the bits of each byte from right to 
	right to left, using str[j] >> i & 1
	Once sent all  text, we send the "\0".
	SIGUSR1 : 1, SIGUSR2 : 0
*/

static void	send_signal(pid_t pid, char *str)
{
	int		i;
	int		j;

	j = -1;
	while (str[++j])
	{
		i = 8;
		while (i--)
		{
			if (str[j] >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

/*
	1. We start, by checking the input arguments.
	2. We calculate the length of the input string
	 and print it : "Bytes sent ..."
	3. We activate the signal function on the client to receive
	the end of each byte (SIGUSER1)
	and/or nullterminated string (SIGUSER2)
	4. We call the function send_signal to send each
	 byte/char in bit
*/

int	main(int argc, char *argv[])
{
	int len_str;
	
	len_str = ft_strlen(argv[2]);
	if (argc != 3 || !len_str || !ft_atoi(argv[1]))
		ft_exit_failure();
	ft_putstr_fd("Bytes sent        : ", STDOUT_FILENO);
	ft_putnbr_fd(len_str, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putstr_fd("Bytes received    : ", STDOUT_FILENO);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}

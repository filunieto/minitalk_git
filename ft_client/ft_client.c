/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:07:05 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/26 18:56:52 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"

static void	ft_exit_failure(void)
{
	write(1, "Usage case: \"./client SERVER_PID MESSAGE\" \n", 43);
	exit(EXIT_FAILURE);
}

/*
	Funcion que recibe las señales del server cada 
	byte(SIGUSR2), e imprime el total y
	nullterminated (SIGUSR1). 
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

static void	send_signal(pid_t pid, char *str)
{
	int		i;
	//char	c;
	int		j;

	j = -1;
	while (str[++j])
	{
		i = 8;
		//c = str[j];
		//manda los bits de derecha a izquierda o al reves
		while (i--)
		{
			if (str[j] >> i & 1)
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

/*
	1. Empezamos, verificando los argumentos que
	 le llegan al cliente
	2. Calculamos la longitud del string de
	 entrada y lo imprimimos
	3. Activamos la funcion signal en el cliente para recibir
	el final de cada byte(siguser1)
	y/o nullterminated string (SIGUS2)
	4. Llamamos a la funcion send_signal para el envio de
	 cada byte/char en bit
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
	signal(SIGUSR1, action); //atencion con el orden de estas funciones. Deben de estar antes de send_signal
	signal(SIGUSR2, action);
	send_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
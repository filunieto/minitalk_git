/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 12:20:54 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/08/26 18:38:42 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

//No escribir aqui

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context; //esto hay que ponerlo siempre. pertenece al tipo de funcion
	if (!client_pid) //por qué hay que asegurar esto? He cambiado  (!client_pid) por (info->si_pid)
		client_pid = info->si_pid;
	c = c | (sig == SIGUSR1); // Si recibimos 1 : c = 0000,0000 | (0000,0001) = 0000,0001
	if (++i == 8) //enta al final del caracter. Ponemo el incremento de i
	{
		i = 0;
		if (!c) //ademas de final de caracter, es el nulterminated?
		{
			//entra aqui al final del string
			kill(client_pid, SIGUSR1); //el server manda esta senal al cliente como final de mensaje
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1); //cambiar por un write
		c = 0;
		kill(client_pid, SIGUSR2); //envia una senal al final de la letra, al cleinet para que incremente el contador de caracteres
	}
	else
		c = c << 1; //terminar de entedner esto
}


int	main(void)
{
	struct sigaction	s_sigaction;
	pid_t pid_server;

	pid_server = getpid();
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(pid_server, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while(1)
		pause();
	return(0);
}

// int	main(void)
// {
// 	struct sigaction	s_sigaction;
// 	pid_t pid_server;

// 	pid_server = getpid();
// 	ft_putstr_fd("Server PID: ", 1);
// 	ft_putnbr_fd(pid_server, 1);
// 	ft_putchar_fd('\n', 1);
// 	s_sigaction.sa_sigaction = action;
// 	s_sigaction.sa_flags = SA_SIGINFO;
// 	sigaction(SIGUSR2, &s_sigaction, 0);
// 	sigaction(SIGUSR1, &s_sigaction, 0);
// 	while (1)
// 		pause();
// 	return (0);
// }

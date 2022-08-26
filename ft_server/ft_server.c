/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:03:13 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/26 20:02:47 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// en git estoy: (HEAD, origin/main, origin/HEAD)
// en lugar de así : (HEAD -> main, origin/main, origin/HEAD)
//he creado una rama 
//* commit fcdd30d1b8b91389eb83c40d2bd469c4b3066a28 (HEAD, origin/main, origin/HEAD, before_bonus)
//me cambio a l arama "before_bonus"
//* commit fcdd30d1b8b91389eb83c40d2bd469c4b3066a28 (HEAD -> before_bonus, origin/main, origin/HEAD)
#include "../include/mini_talk.h"

// Se llama a esta funcion cada vez que se recibe o bien SIUSr1 (1) o SIGUSER2 (0)
/*
	Si recibe (SIGUSR1) o 1 -> c = c | (sig == SIGUSR1) === c = 0000 0000 | 0000 0001
	Si recibe (SIGUSR2) o 0 -> c = c | (sig == SIGUSR1) === c = 0000 0000 | 0000 0000
*/

static void	action(int sig, siginfo_t *info, void* context)
{
	static int	i = 0;
	//static pid_t	pid_client = 0; //si ponemos static guarda el pid
	pid_t	pid_client;

	static unsigned char c = 0;
	(void)context; //esto hay que ponerlo siempre. pertenece al tipo de funcion
	if (info->si_pid) //por qué hay que asegurar esto? Quizá  (!client_pid) por (info->si_pid) funcioanria?
		pid_client = info->si_pid;
	c = c | (sig == SIGUSR1); // Si recibimos 1 : c = 0000,0000 | (0000,0001) = 0000,0001
	//Solo entra en if cuando i == 8. Aunque no se entre en if, incrementa el i
	if (++i == 8) 
	{
		i = 0;
		if (!c)
		{
			kill(pid_client, SIGUSR1);
			//pid_client = 0; //si cambiamos el el if del 22 : if (!pid_client), podrmiamos anular estalinea?
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(pid_client, SIGUSR2);
	}
	else //esto se ejecuta si el byte no está completo y hay que seguir anadiendo 1 o 0 al char
		c = c << 1; //desplazamos los bits una posicion a la izquierda
}

/*
	1. Imprimimos el pid del server.
	2. Definimos sigation struct, la cual tomara la funcion
	 que se ejecutara cuando el server reciba las señales, esto
	 es: recibir las señales binarias y transformarlas en char;
	 cada 8 señales, se enviara una señal al cliente;
	 y al final del string, otra señal para finalizar.
*/

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
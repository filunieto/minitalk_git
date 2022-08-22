/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:03:13 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/22 20:01:20 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"
// es posible que la static , guarde un valor residual cada vez que se le llama? creo que se iniciali
void	handler_sigusr(int signum)
{
   static char	c = 0xFF; // cuando lo igualo a 255 , da poblemas , unsigned char, tambien da probelmas (quiza combinado con printf o no), mejor probar con int
   static int	bits = 0;

   if (signum == SIGUSR2)
   {
   	//printf("0");
	write(1, "0", 1);
   	c = c ^ 0x80 >> bits;
	//printf("\nSIGUSER2 ^ %c\n", c);

   }
   else if (signum == SIGUSR1)
   {
   	//printf("1");
	write(1, "1", 1); //cuando la salida se hace por "2" :write(2, "1", 1); hay probelmas en el primer numero y cosas raras. con printf todo va bien
   	c = c | 0x80 >> bits;
	//printf("\nSIGUSER1 | %c\n", c);

   }
   bits++;
   if (bits == 8)
   {
   	write(1, "-> ", 3);
   	write(1, &c, 1);
   	write(1, "\n", 1);
	//printf("-> %c\n", c);
   	bits = 0;
   	c = 0xFF;
   }
}

int	main(void)
{
   pid_t		pid;

   pid = getpid();
   printf("PID: %d\n", pid);
   signal(SIGUSR1, handler_sigusr);
   signal(SIGUSR2, handler_sigusr);
   while (1)
   	pause();
}
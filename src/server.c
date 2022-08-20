/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:03:13 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/20 15:04:41 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"

void	handler_sigusr1(int signum)
{
 	(void)signum;
	write(2, "1", 1);

}

void	handler_sigusr2(int signum)
{
 	(void)signum;
	write(2, "0", 1);
}
// void	handler_sigusr2(int signum)
// {
	
// 	(void)signum;
// 	printf("0");
// }

int	main(void)
{
   pid_t	pid;

   pid = getpid();
   printf("PID: %d\n", pid);
   signal(SIGUSR1, handler_sigusr1);
   signal(SIGUSR2, handler_sigusr2);

   while (1)
		pause();
}


// void	handler_sigusr2(int signum)
// {
	
// 	(void)signum;
// 	printf("0");
// }

// void	handler_sigusr1(int signum)
// {
	
// 	(void)signum;
// 	printf("1");
// }

// int main(void)
// {
// 	pid_t	pid;

// 	pid = getpid();
// 	printf("PID: %d\n", pid);
// 	signal(SIGUSR1, handler_sigusr1);
// 	signal(SIGUSR2, handler_sigusr2);
// 	while (1)
// 		pause();
// 	return(0);	
// }
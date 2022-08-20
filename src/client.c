/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:07:05 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/20 17:32:39 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"

void	send_string(char *str, int pid)
{
	int i;
	int	bitshift;
 

	i = -1;
	while (str[++i])
	{
		bitshift = -1;
		while (++bitshift < 8)
		{
			//printf("en while %c[%d] y PID %i\n", caracter, caracter, pid);
			if (str[i] & 128 >> bitshift)
			{
				write(2, "1", 1);
				kill(pid, SIGUSR1);
			}
			else
			{
				//printf("cliente entra en else 0\n");
				write(2, "0", 1);
				kill(pid, SIGUSR2);
			}
			usleep(3);
		}
		//printf("\n");
	}
}

int	main(int argc, char **argv)
{
	int	pid;	

	if (argc != 3)
	{
		printf("client: invalid number of arguments.  necesito un PID y un string\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	// kill(pid, SIGUSR1);
	// sleep(2);
	// kill(pid, SIGUSR2);
	// sleep(2);
	send_string(argv[2], pid);
	printf("\n%s y PID %i\n", argv[2], pid);

	//printf("final del cliente\n");
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	int	pid;
// 	int	bitshift;
// 	char caracter;
	
// 	if (argc != 3)
// 	{
// 		printf("client: invalid number of arguments.  necesito un PID y un char\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	pid = atoi(argv[1]);
// 	caracter = argv[2][0];
// 	printf("%c[%d] y PID %i\n", caracter, caracter, pid);
// 	bitshift = -1;
// 	kill(pid, SIGUSR1);
// 	kill(pid, SIGUSR2);
// 	while (++bitshift < 8)
// 	{
// 		if (caracter & 128 >> bitshift)
// 		{
// 			kill(pid, SIGUSR1);
// 		}
// 		else
// 		{
// 			kill(pid, SIGUSR2);
// 		}
// 		usleep(3);
// 	}
// 	return (0);
// }
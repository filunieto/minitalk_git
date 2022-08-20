/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:07:05 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/20 12:12:00 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"

int	main(int argc, char **argv)
{
	int	pid;
	
	if (argc != 2)
	{
		printf("client: invalid number of arguments. 2 argumentos máximo\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}
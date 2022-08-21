/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:23:24 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/20 13:51:04 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"

int	main(int argc, char **argv)
{
	//int	i;
	int	bitshift;
	char caracter;
	
	if (argc != 2)
	{
		printf("client: invalid number of arguments. 2 argumentos máximo\n");
		return (1);
	}
	caracter = argv[1][0];
	bitshift = -1;
	printf("%c[%d]: \n", caracter, caracter);
	while(++bitshift < 8)
	{
		if (caracter & 128 >> bitshift)
			printf("1");
		else
			printf("0");
		// printf(" .  0x80 : [%d]:, caracter & 0x80 >> bitshift : %c[%d]:\n",
		//    0x80, caracter & 0x80 >> bitshift, caracter & 0x80 >> bitshift);
	}
	printf("\n");
	return (0);
}
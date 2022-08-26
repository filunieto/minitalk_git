/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:03:13 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/26 13:17:42 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_talk.h"

/*
	1. Imprimimos el pid del server.
	2. Definimos sigation struct, la cual tomara la funcion
	 que se ejecutara cuando el server reciba las señales, esto
	 es: recibir las señales binarias y transformarlas en char;
	 cada 8 señales, se enviara una señal al cliente;
	 y al final del string, otra señal para finalizar.
*/

int	main(int argc, char **argv)
{

	
	while (1)
		pause();
	return (0);
}
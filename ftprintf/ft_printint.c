/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:59:47 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_printint(t_io *io, t_mod *mods)
{
	int	nbr;

	nbr = va_arg(io->ap, int);
	if (nbr == -2147483648)
	{
		mods->putminus = 1;
		ft_printnbr(io, mods, 2147483648);
		return ;
	}
	if (nbr < 0)
	{
		mods->putminus = 1;
		nbr = nbr * -1;
	}
	ft_printnbr(io, mods, (unsigned long int) nbr);
}

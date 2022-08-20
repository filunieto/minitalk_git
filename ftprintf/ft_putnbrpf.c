/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:06:01 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static char	ft_choosechar(t_mod *mods, unsigned long int nbr)
{
	char	c;

	if (nbr < 10)
		c = nbr + '0';
	else if (mods->conspec == 'X')
		c = nbr - 10 + 'A';
	else
		c = nbr - 10 + 'a';
	return (c);
}

void	ft_putnbrpf(t_io *io, t_mod *mods, unsigned long int nbr)
{
	char	c;

	if (nbr < (unsigned long int) mods->base)
	{
		c = ft_choosechar(mods, nbr);
		io->nprinted += write(1, &c, 1);
		return ;
	}
	ft_putnbrpf(io, mods, nbr / mods->base);
	c = ft_choosechar(mods, nbr % mods->base);
	io->nprinted += write(1, &c, 1);
}

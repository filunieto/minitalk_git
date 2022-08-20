/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:23:51 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_numlen(t_mod *mods, long unsigned int nbr)
{
	int	numlen;

	if (!mods->precision && !nbr)
		return (0);
	numlen = 1;
	while (nbr / mods->base > 0)
	{
		numlen++;
		nbr = nbr / mods->base;
	}
	return (numlen);
}

static int	ft_preflen(t_mod *mods, unsigned long int nbr)
{
	int	preflen;

	preflen = 0;
	if (mods->putminus || mods->plus || mods->space)
		preflen = 1;
	else if (mods->altform && nbr)
		preflen = 2;
	else if (mods->conspec == 'p')
		preflen = 2;
	return (preflen);
}

static void	ft_putprefix(t_io *io, t_mod *mods, unsigned long int nbr)
{
	if (mods->putminus)
		io->nprinted += write(1, "-", 1);
	else if (mods->plus)
		io->nprinted += write(1, "+", 1);
	else if (mods->space)
		io->nprinted += write(1, " ", 1);
	else if (mods->altform && mods->conspec == 'X' && nbr)
		io->nprinted += write(1, "0X", 2);
	else if (mods->altform && mods->conspec == 'x' && nbr)
		io->nprinted += write(1, "0x", 2);
	else if (mods->conspec == 'p')
		io->nprinted += write(1, "0x", 2);
}

static void	ft_putpreczeros(t_io *io, t_mod *mods, int len)
{
	int	preczeros;

	if (mods->precision > len)
	{
		preczeros = mods->precision - len;
		while (preczeros)
		{
			io->nprinted += write(1, "0", 1);
			preczeros--;
		}
	}
}

void	ft_printnbr(t_io *io, t_mod *mods, unsigned long int nbr)
{
	int	numlen;
	int	preflen;
	int	preczeros;

	numlen = ft_numlen(mods, nbr);
	preflen = ft_preflen(mods, nbr);
	preczeros = 0;
	if (mods->precision > numlen)
		preczeros = mods->precision - numlen;
	if (mods->width > numlen + preczeros + preflen)
		mods->pads = mods->width - numlen - preczeros - preflen;
	if (mods->zeropad)
		ft_putprefix(io, mods, nbr);
	if (!mods->leftadj && mods->pads)
		ft_pad(io, mods);
	if (!mods->zeropad)
		ft_putprefix(io, mods, nbr);
	ft_putpreczeros(io, mods, numlen);
	if (mods->precision || nbr)
		ft_putnbrpf(io, mods, nbr);
	if (mods->pads && mods->leftadj)
		ft_pad(io, mods);
}

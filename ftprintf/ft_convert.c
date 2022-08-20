/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:14:44 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:42 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_adjustmods(t_mod *mods)
{
	if (mods->conspec == 'i' || mods->conspec == 'd'
		|| mods->conspec == 'u')
	{
		mods->altform = 0;
		mods->base = 10;
	}
	if (mods->conspec == 'u' || mods->conspec == 'x'
		|| mods->conspec == 'X' || mods->conspec == 'p')
	{
		mods->plus = 0;
		mods->space = 0;
	}
	if (mods->conspec == 'x' || mods->conspec == 'X'
		|| mods->conspec == 'p')
		mods->base = 16;
	if (mods->precision >= 0 && mods->conspec != 'c'
		&& mods->conspec != 's' && mods->conspec != '%')
		mods->zeropad = 0;
}

void	ft_convert(t_io *io, t_mod *mods)
{
	mods->conspec = io->format[io->pos];
	ft_adjustmods(mods);
	if (mods->conspec == 'c' || mods->conspec == '%')
		ft_printchar(io, mods);
	else if (mods->conspec == 's')
		ft_printstr(io, mods);
	else if (mods->conspec == 'i' || mods->conspec == 'd')
		ft_printint(io, mods);
	else if (mods->conspec == 'u' || mods->conspec == 'x'
		|| mods->conspec == 'X')
		ft_printnbr(io, mods, (unsigned long int) va_arg(io->ap, unsigned int));
	else if (mods->conspec == 'f')
		ft_printfloat(io, mods);
	else
		ft_printnbr(io, mods, va_arg(io->ap, unsigned long int));
}

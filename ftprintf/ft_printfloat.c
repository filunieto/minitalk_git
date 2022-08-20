/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:46:39 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<math.h>

void	my_modf(double nbr, double *int_part, double *fract_part)
{
	if (nbr < 0)
	{
		*int_part = ceil(nbr);
		*fract_part = -1 * (nbr - *int_part);
	}
	else
	{
		*int_part = floor(nbr);
		*fract_part = nbr - *int_part;
	}
}

void	set_float_precision(t_mod *mods, double fract_part)
{
	double	fract_part_int;
	double	fract_part_new;
	double	precision;

	precision = 0;
	while (precision < 15)
	{
		if (fract_part < 0.0000011 || fract_part > 0.999998)
			break ;
		precision++;
		fract_part_new = fract_part * 10;
		my_modf(fract_part_new, &fract_part_int, &fract_part);
	}
	if (mods->precision == -1 || precision < mods->precision)
		mods->precision = precision;
}

void	ft_printfloat(t_io *io, t_mod *mods)
{
	double	nbr;
	double	int_part;
	double	fract_part;

	nbr = va_arg(io->ap, double);
	mods->base = 10;
	my_modf(nbr, &int_part, &fract_part);
	if (nbr < 0)
	{
		io->nprinted += write(1, "-", 1);
		int_part *= -1;
	}
	ft_putnbrpf(io, mods, (unsigned long) int_part);
	set_float_precision(mods, fract_part);
	if (mods->precision == 0)
		return ;
	io->nprinted += write(1, ".", 1);
	while (mods->precision)
	{
		fract_part *= 10;
		my_modf(fract_part, &int_part, &fract_part);
		ft_putnbrpf(io, mods, (unsigned long) int_part);
		mods->precision--;
	}
}

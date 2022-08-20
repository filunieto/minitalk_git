/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:05:05 by fnieves-          #+#    #+#             */
/*   Updated: 2022/04/19 16:56:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_zeroisflag(t_io *io)
{
	int	i;

	i = 1;
	while (io->format[io->pos - i] == '0')
		i++;
	if (ft_isdigit(io->format[io->pos - i]) || io->format[io-> pos - i] == '.')
		return (0);
	return (1);
}

static void	ft_width(t_io *io, t_mod *mods)
{
	if (io->format[io->pos] == '*')
		mods->width = va_arg(io->ap, int);
	else if (io->format[io->pos - 1] == '0' && ft_zeroisflag(io))
		mods->width = io->format[io->pos] - '0';
	else if (!ft_isdigit(io->format[io->pos - 1]))
		mods->width = io->format[io->pos] - '0';
	else
		mods->width = (mods->width * 10) + (io->format[io->pos] - '0');
}

static void	ft_precision(t_io *io, t_mod *mods)
{
	if (io->format[io->pos] == '*')
	{
		mods->precision = va_arg(io->ap, int);
		mods->adj_precision = 0;
		return ;
	}
	else if (!ft_isdigit(io->format[io->pos - 1]))
		mods->precision = io->format[io->pos] - '0';
	else
		mods->precision = (mods->precision * 10) + (io->format[io->pos] - '0');
	if (!ft_isdigit(io->format[io->pos + 1]))
		mods->adj_precision = 0;
}

void	ft_modifiers(t_io *io, t_mod *mods)
{
	if (io->format[io->pos] == '0' && ft_zeroisflag(io))
		mods->zeropad = 1;
	else if (ft_isdigit(io->format[io->pos]) && !mods->adj_precision)
		ft_width(io, mods);
	else if (ft_isdigit(io->format[io->pos]))
		ft_precision(io, mods);
	else if (io->format[io->pos] == '*' && !mods->adj_precision)
		ft_width(io, mods);
	else if (io->format[io->pos] == '*')
		ft_precision(io, mods);
	else if (io->format[io->pos] == '+')
		mods->plus = 1;
	else if (io->format[io->pos] == '-')
		mods->leftadj = 1;
	else if (io->format[io->pos] == ' ')
		mods->space = 1;
	else if (io->format[io->pos] == '#')
		mods->altform = 1;
	else if (io->format[io->pos] == '.')
	{
		mods->precision = 0;
		if (ft_isdigit(io->format[io->pos + 1]))
			mods->adj_precision = 1;
	}
}

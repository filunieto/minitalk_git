/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:59:17 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void	ft_initio(t_io *io, const char *format, va_list ap)
{
	io->format = format;
	va_copy(io->ap, ap);
	va_end(ap);
	io->nprinted = 0;
	io->pos = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_mod	mods;
	t_io	io;

	va_start(ap, format);
	ft_initio(&io, format, ap);
	ft_initmods(&mods);
	ft_parse(&io, &mods);
	va_end(ap);
	return (io.nprinted);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:39:33 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_pad(t_io *io, t_mod *mods)
{
	char	c;

	if (mods->zeropad && !mods->leftadj)
		c = '0';
	else
		c = ' ';
	while (mods->pads)
	{
		io->nprinted += write(1, &c, 1);
		mods->pads--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmods.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:56:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/04/19 16:55:10 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_initmods(t_mod *mods)
{
	mods->altform = 0;
	mods->zeropad = 0;
	mods->leftadj = 0;
	mods->space = 0;
	mods->plus = 0;
	mods->width = 0;
	mods->precision = -1;
	mods->adj_precision = 0;
	mods->conspec = 0;
	mods->base = 0;
	mods->putminus = 0;
	mods->pads = 0;
}

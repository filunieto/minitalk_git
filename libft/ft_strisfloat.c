/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:45:28 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

static int	is_valid(char *s, int sign, int i)
{
	int	digits;
	int	nonzero;

	digits = 0;
	nonzero = 0;
	while (ft_isdigit(s[i]))
	{
		digits++;
		if (s[i] != '0')
			nonzero++;
		i++;
	}
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
	{
		digits++;
		if (s[i] != '0')
			nonzero++;
		i++;
	}
	if (s[i] || digits < 1 || digits > 15 || (!nonzero && sign))
		return (0);
	return (1);
}

/*
// returns 1 if string is float or double, otherwise, returns 0
*/
int	ft_strisfloat(char *s)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (s == NULL)
		return (0);
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		sign = 1;
		i++;
	}
	return (is_valid(s, sign, i));
}

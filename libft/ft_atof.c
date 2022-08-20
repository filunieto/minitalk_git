/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:52:22 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*initial_part(char *ptr, int *sign)
{
	*sign = 1;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '+')
		ptr++;
	if (*ptr == '-')
	{
		*sign = -1;
		ptr++;
	}
	return (ptr);
}

double	ft_atof(const char *s)
{
	char	*ptr;
	int		sign;
	double	nbr;
	int		power;

	nbr = 0;
	ptr = (char *) s;
	if (!ft_strisfloat(ptr))
		return (0);
	ptr = initial_part(ptr, &sign);
	while (ft_isdigit(*ptr))
	{
		nbr = (nbr * 10) + *ptr - '0';
		ptr++;
	}
	if (*ptr == '.')
		ptr++;
	power = 1;
	while (*ptr && ft_isdigit(*ptr))
	{
		nbr = nbr + ((*ptr - '0') / ft_pow(10, power));
		power++;
		ptr++;
	}
	return (sign * nbr);
}

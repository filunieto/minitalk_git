/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:26:56 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_edge(void)
{
	char	*s;

	s = ft_calloc(12, sizeof(char));
	if (s == NULL)
		return (NULL);
	s = ft_memcpy(s, "-2147483648", 11);
	return (s);
}

static char	*ft_nul(void)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	s[0] = '0';
	return (s);
}

static char	*ft_nbr(int n)
{
	int		len;
	char	*s;

	if (n < 0)
	{
		n = n * -1;
		len = ft_len(n) + 1;
	}
	else
		len = ft_len(n);
	s = ft_calloc(len + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	while (n > 0)
	{
		s[len - 1] = (n % 10) + '0';
		n = n / 10;
		len --;
	}
	if (len > 0)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_edge());
	if (n == 0)
		return (ft_nul());
	return (ft_nbr(n));
}

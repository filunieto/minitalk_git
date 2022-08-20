/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:48:04 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (src >= dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len > 0)
		{
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	}
	return (dst);
}

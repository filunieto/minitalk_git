/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:04:57 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	newlen;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s1);
	newlen = len1 + ft_strlen(s2);
	newstr = malloc(sizeof(char) * (newlen + 1));
	if (!newstr)
		return (NULL);
	while (i < len1)
	{
		newstr[i] = s1[i];
		i++;
	}
	while (i < newlen)
	{
		newstr[i] = s2[i - len1];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

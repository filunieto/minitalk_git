/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:31:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_trim(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_trimstart(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_trim(s1[i], set))
	{
		i++;
	}
	return (i);
}

static size_t	ft_trimend(const char *s1, const char *set, size_t len)
{
	size_t	j;

	j = 0;
	while (j < len && ft_trim(s1[len - 1 - j], set))
	{
		j++;
	}
	if (j == len)
		return (0);
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trim_start;
	size_t	trimlen;
	size_t	len;
	char	*trimmed;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	trim_start = ft_trimstart(s1, set);
	trimlen = len - trim_start - ft_trimend(s1, set, len);
	trimmed = malloc(sizeof(char) * (trimlen + 1));
	if (trimmed == NULL)
		return (NULL);
	trimmed[trimlen] = '\0';
	while (trimlen > 0)
	{
		trimmed[trimlen - 1] = s1[trim_start + trimlen - 1];
		trimlen --;
	}
	return (trimmed);
}

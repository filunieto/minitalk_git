/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:21:52 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/12 17:13:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_countsubs(const char *s, char c, size_t *nsubs)
{
	char	*trav;

	*nsubs = 0;
	if (s == NULL)
		return ;
	trav = (char *)s;
	while (*trav)
	{
		if (*trav == c)
			trav++;
		else
		{
			(*nsubs)++;
			while (*trav && *trav != c)
				trav++;
		}
	}
}

void	ft_free(char ***arr, size_t i_failedsub)
{
	size_t	i;

	i = 0;
	while (i < i_failedsub)
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}

char	*ft_makesub(char *trav, char c, size_t *sublen)
{
	char	*endofsub;
	char	*sub;

	endofsub = ft_strchr(trav, c);
	if (endofsub == NULL)
		*sublen = ft_strlen(trav);
	else
		*sublen = endofsub - trav;
	sub = ft_calloc(((*sublen) + 1), sizeof(char));
	if (sub == NULL)
		return (NULL);
	return (ft_memcpy(sub, trav, *sublen));
}

void	ft_fillarr(const char *s, char c, size_t nsubs, char ***arr)
{
	char	*trav;
	size_t	sublen;
	size_t	i;

	i = 0;
	trav = (char *)s;
	while (i < nsubs)
	{
		while (*trav == c)
			trav++;
		(*arr)[i] = ft_makesub(trav, c, &sublen);
		if ((*arr)[i] == NULL)
			ft_free(arr, i);
		i++;
		trav = trav + sublen;
	}
	(*arr)[i] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	nsubs;

	if (s == NULL)
		return (NULL);
	ft_countsubs(s, c, &nsubs);
	arr = malloc((nsubs + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	ft_fillarr(s, c, nsubs, &arr);
	return (arr);
}

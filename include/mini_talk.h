/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 07:15:09 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/22 15:09:03 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //recuerda borrar

# include "../libft/libft.h"
# include "../ftprintf/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}


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




#endif

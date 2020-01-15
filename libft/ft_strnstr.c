/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:26:01 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/20 20:40:16 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checker(const char *str1,
		const char *str2, size_t len, size_t save)
{
	size_t			i;

	i = 0;
	while (str1[i] == str2[i] && str2[i] != '\0' && len > save)
	{
		i++;
		save++;
	}
	if (str2[i] == '\0')
		return (1);
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	size_t			j;
	const char		*start;

	start = s2;
	j = 0;
	if (!*s2)
		return ((char*)s1);
	while (len > j && *s1)
	{
		if (*s1 == *s2 && *s1)
		{
			i = j;
			if (ft_checker(s1, s2, len, i) == 1)
				return ((char *)s1);
			s2 = start;
		}
		s1++;
		j++;
	}
	return (NULL);
}

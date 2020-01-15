/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:47:41 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/20 20:22:03 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *i;
	const char *j;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		i = s1;
		j = s2;
		while (*j != '\0' && *i == *j)
		{
			i++;
			j++;
		}
		if (*j == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:49:55 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/21 17:46:04 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s || !(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len > 0 && s[i])
	{
		new[i] = s[start];
		i++;
		start++;
		len--;
	}
	new[i] = '\0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:39:00 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/21 18:03:28 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*i;
	char			*j;
	int				size;
	unsigned int	size2;

	if (s == NULL || f == NULL)
		return (NULL);
	size = 0;
	size2 = 0;
	while (s[size])
		size++;
	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = (char*)s;
	j = new;
	while (*i)
	{
		*j = f(size2, *i);
		j++;
		i++;
		size2++;
	}
	new[size] = '\0';
	return (new);
}

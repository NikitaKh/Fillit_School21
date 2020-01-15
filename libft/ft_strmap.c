/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:03:46 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/21 18:13:10 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*i;
	size_t	j;
	char	*k;

	if (s == NULL || f == NULL)
		return (NULL);
	j = 0;
	while (s[j])
		j++;
	if (!(new = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = (char*)s;
	k = new;
	while (*i)
		*(k++) = f(*(i++));
	new[j] = '\0';
	return (new);
}

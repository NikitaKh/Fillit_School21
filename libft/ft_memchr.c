/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:46:37 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/20 20:19:01 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char*)s;
	while (n > 0)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		n--;
		tmp++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:50:28 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/16 21:01:09 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && *(char*)s1 == *(char*)s2)
	{
		s1 = (char*)s1 + 1;
		s2 = (char*)s2 + 1;
	}
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}

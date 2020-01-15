/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:10:22 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/20 20:13:50 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	new_dst = dst;
	new_src = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		new_dst[i] = new_src[i];
		i++;
	}
	return (new_dst);
}

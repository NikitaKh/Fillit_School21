/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:52:21 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/21 17:38:56 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int	*new;

	if (!(new = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	new = (int*)malloc(sizeof(int) * size);
	ft_bzero(new, size);
	return (new);
}

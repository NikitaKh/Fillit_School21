/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:35:32 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/21 16:01:47 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;
	char *tmp;

	if (size + 1 < size)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	tmp = new;
	while (size > 0)
	{
		*new = '\0';
		new++;
		size--;
	}
	*new = '\0';
	new = tmp;
	return (new);
}

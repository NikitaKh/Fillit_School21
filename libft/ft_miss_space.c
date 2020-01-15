/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miss_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 00:14:27 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/21 18:47:00 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_miss_space(const char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			&& str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	i--;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
	{
		i--;
		j--;
	}
	return (j);
}

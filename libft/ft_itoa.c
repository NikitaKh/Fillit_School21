/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:37:39 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/21 23:35:14 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	*new;
	int		j;

	j = ft_count_num(n);
	if (!(new = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	new[j] = '\0';
	if (n == 0)
	{
		new[0] = 48;
		return (new);
	}
	if (n < 0)
	{
		n = -n;
	}
	while (j-- > 0)
	{
		new[j] = '0' + (n % 10) * (n < 0 ? -1 : 1);
		n = n / 10;
	}
	if (new[0] == '0' && new[1] != '\0')
		new[0] = '-';
	return (new);
}

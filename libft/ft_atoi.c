/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:41:01 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/21 23:34:53 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_over(int i)
{
	if (i == -1)
		return (0);
	else
		return (-1);
}

int				ft_atoi(const char *str)
{
	int			num;
	int			sign;
	long long	max;
	long long	prev;

	num = 0;
	max = 0;
	prev = 0;
	sign = 1;
	while ((*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		str -= (sign = (-1));
	else if (*str == '+')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		max = max * 10 + (*str - '0');
		if (max < prev || max >= 9223372036854775807)
			return (check_over(sign));
		prev = max;
		str++;
	}
	return (max * sign);
}

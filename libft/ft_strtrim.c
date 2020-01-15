/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:29:01 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/21 19:00:23 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_xxx(char *new, const char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		new[j] = s[i];
		i++;
		j++;
	}
	if (j > 0)
		j--;
	while (new[j] == ' ' || new[j] == '\n' || new[j] == '\t')
		j--;
	j++;
	new[j] = '\0';
	return (new);
}

char		*ft_strtrim(char const *s)
{
	char	*new;

	if (!s)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (ft_miss_space(s) + 1))))
		return (NULL);
	if (ft_miss_space(s) == 0)
	{
		new[0] = '\0';
		return (new);
	}
	return (ft_xxx(new, s));
}

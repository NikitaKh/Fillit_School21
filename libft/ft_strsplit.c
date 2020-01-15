/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:55:20 by cgoliath          #+#    #+#             */
/*   Updated: 2019/09/19 18:08:47 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_del(char **as, int i)
{
	while (i > 0)
		free(as[i--]);
	free(as);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**new;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	if (!s || !(new = (char**)malloc(sizeof(char*) * (ft_count_w(s, c) + 1))))
		return (NULL);
	while ((k = 0) || s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if (!(new[j] = (char*)malloc(sizeof(char)
							* (ft_len(s + i, c) + 1))))
				return (ft_del(new, j));
			while (s[i] != '\0' && s[i] != c)
				new[j][k++] = s[i++];
			new[j++][k] = 0;
		}
	}
	new[j] = 0;
	return (new);
}

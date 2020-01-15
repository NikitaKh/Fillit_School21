/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:42:49 by cgoliath          #+#    #+#             */
/*   Updated: 2019/11/24 20:24:01 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUFFER 544

int			side_count(char *block)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (block[i] == '#')
		{
			if (i + 1 <= 18 && block[i + 1] == '#')
				++count;
			if (i - 1 >= 0 && block[i - 1] == '#')
				++count;
			if (i + 5 <= 18 && block[i + 5] == '#')
				++count;
			if (i - 5 >= 0 && block[i - 5] == '#')
				++count;
		}
		i++;
	}
	return (count);
}

int			char_count(char *block)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (block[i] != '\n' && block[i] != '#' && block[i] != '.' && block[i])
			return (0);
		if (block[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (block[i] == '#')
			++count;
		i++;
	}
	if (block[i] != '\n' || !block[i])
		return (0);
	return (count);
}

int			check_valid(char *block, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		if (side_count(block + i) != 6 && side_count(block + i) != 8)
			return (0);
		if (char_count(block + i) != 4)
			return (0);
		i = i + 21;
	}
	return (1);
}

int			read_and_check(char *file)
{
	int		fd;
	int		bytes;
	char	buf[BUFFER + 1];

	fd = open(file, O_RDONLY);
	bytes = read(fd, buf, BUFFER + 1);
	close(fd);
	if (bytes > BUFFER || bytes < 19)
		return (0);
	buf[bytes] = '\0';
	if (!check_valid(buf, bytes))
		return (0);
	return (1);
}

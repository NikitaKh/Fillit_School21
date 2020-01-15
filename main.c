/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:09:55 by cgoliath          #+#    #+#             */
/*   Updated: 2019/11/30 21:08:43 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		*reader(char *file)
{
	char	letter;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	letter = 'A';
	fd = open(file, O_RDONLY);
	return (reader_norm(fd, letter, i, j));
}

t_tetr		*reader_norm(int fd, char letter, int i, int j)
{
	char	buf[22];
	t_tetr	*full_tetrs;
	char	temp[4][5];
	int		ii;

	full_tetrs = NULL;
	while (read(fd, buf, 21) > 0)
	{
		buf[21] = '\0';
		while (i < 4)
		{
			while (buf[ii] != '\n' && buf[ii] != '\0')
				temp[i][j++] = buf[ii++];
			temp[i++][j] = '\0';
			j = 0;
			ii++;
		}
		coord(temp, &full_tetrs, letter++);
		i = 0;
		j = 0;
		ii = 0;
	}
	close(fd);
	return (full_tetrs);
}

int			main(int argc, char **argv)
{
	t_tetr	*full_tetrs;
	int		min_size;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if (!read_and_check(argv[1]))
	{
		ft_putstr("error\n");
		return (1);
	}
	full_tetrs = reader(argv[1]);
	min_size = ft_min_size(ft_list_len(&full_tetrs));
	solve(full_tetrs, min_size);
	delete_tetr(&full_tetrs);
	return (0);
}

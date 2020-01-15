/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:26:34 by spalmer           #+#    #+#             */
/*   Updated: 2019/11/30 18:05:47 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		delete_tetr(t_tetr **full_tetrs)
{
	t_tetr	*temp;

	temp = NULL;
	while (*full_tetrs)
	{
		temp = (*full_tetrs)->next;
		free(*full_tetrs);
		*full_tetrs = temp;
	}
}

t_map		*delete_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
	return (NULL);
}

t_map		*fill_zero_map(t_map *map)
{
	t_map	*temp;
	int		i;
	int		j;

	temp = map;
	i = 0;
	j = 0;
	while (i < map->size)
	{
		while (j <= map->size)
		{
			if (j == map->size)
				temp->map[i][j] = '\0';
			else
				temp->map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (temp);
}

t_map		*make_map(int size)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map*)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->size = size;
	map->map = (char**)malloc(sizeof(char*) * size);
	if (!map->map)
		return (NULL);
	while (i < size)
	{
		map->map[i] = (char*)malloc(sizeof(char) * size);
		if (!map->map[i])
		{
			delete_map(map);
			return (NULL);
		}
		i++;
	}
	map->letter = '.';
	return (fill_zero_map(map));
}

void		print_map(char **map, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (map[i][j] != '\0')
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

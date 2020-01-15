/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:37:55 by spalmer           #+#    #+#             */
/*   Updated: 2019/11/30 18:03:47 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_place(int i, int j, t_map *map, t_tetr *full_tetrs)
{
	int			dif_i;
	int			dif_j;

	if (map->map[i][j] != '.' || i >= map->size || j >= map->size)
		return (0);
	dif_i = full_tetrs->p2[0] - full_tetrs->p1[0];
	dif_j = full_tetrs->p2[1] - full_tetrs->p1[1];
	i = i + dif_i;
	j = j + dif_j;
	if (i >= map->size || j >= map->size || map->map[i][j] != '.')
		return (0);
	dif_i = full_tetrs->p3[0] - full_tetrs->p2[0];
	dif_j = full_tetrs->p3[1] - full_tetrs->p2[1];
	i = i + dif_i;
	j = j + dif_j;
	if (i >= map->size || j >= map->size || map->map[i][j] != '.')
		return (0);
	dif_i = full_tetrs->p4[0] - full_tetrs->p3[0];
	dif_j = full_tetrs->p4[1] - full_tetrs->p3[1];
	i = i + dif_i;
	j = j + dif_j;
	if (i >= map->size || j >= map->size || map->map[i][j] != '.')
		return (0);
	return (1);
}

void			tetramino_to_map(int i, int j, t_map *map, t_tetr *one_tetr)
{
	int			dif_i;
	int			dif_j;

	map->map[i][j] = map->letter;
	dif_i = one_tetr->p2[0] - one_tetr->p1[0];
	dif_j = one_tetr->p2[1] - one_tetr->p1[1];
	i = i + dif_i;
	j = j + dif_j;
	map->map[i][j] = map->letter;
	dif_i = one_tetr->p3[0] - one_tetr->p2[0];
	dif_j = one_tetr->p3[1] - one_tetr->p2[1];
	i = i + dif_i;
	j = j + dif_j;
	map->map[i][j] = map->letter;
	dif_i = one_tetr->p4[0] - one_tetr->p3[0];
	dif_j = one_tetr->p4[1] - one_tetr->p3[1];
	i = i + dif_i;
	j = j + dif_j;
	map->map[i][j] = map->letter;
}

int				recursia(t_tetr *one_tetr, t_map *map, int i, int j)
{
	if (one_tetr == NULL)
		return (0);
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (check_place(i, j, map, one_tetr))
			{
				map->letter = one_tetr->letter;
				tetramino_to_map(i, j, map, one_tetr);
				if (recursia(one_tetr->next, map, 0, 0) == 0)
					return (0);
				else
				{
					map->letter = '.';
					tetramino_to_map(i, j, map, one_tetr);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int				solve(t_tetr *full_tetrs, int size)
{
	t_map		*map;
	t_tetr		*one_tetr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	map = make_map(size);
	one_tetr = full_tetrs;
	while (recursia(one_tetr, map, i, j) != 0)
	{
		size++;
		delete_map(map);
		map = make_map(size);
	}
	print_map(map->map, size);
	delete_map(map);
	return (1);
}

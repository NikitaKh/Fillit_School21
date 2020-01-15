/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:58:44 by spalmer           #+#    #+#             */
/*   Updated: 2019/11/30 17:58:13 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_min_size(int cnt)
{
	int		i;
	int		temp;

	i = 0;
	temp = cnt * 4;
	while (i * i < temp)
		i++;
	return (i);
}

int			ft_list_len(t_tetr **tetrs)
{
	t_tetr	*temp;
	int		cnt;

	cnt = 0;
	temp = *tetrs;
	while (temp)
	{
		temp = temp->next;
		cnt++;
	}
	return (cnt);
}

int			ft_lst_back(t_tetr **tetrs, t_tetr *new)
{
	t_tetr	*temp;

	if (!tetrs || !new)
		return (0);
	temp = *tetrs;
	if (!temp)
		*tetrs = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}

t_tetr		*make_list_tetramino(int *coord, char letter)
{
	t_tetr	*tetrs;

	if (!(tetrs = (t_tetr*)malloc(sizeof(t_tetr))))
		return (NULL);
	if (coord)
	{
		tetrs->p1[0] = coord[0];
		tetrs->p1[1] = coord[1];
		tetrs->p2[0] = coord[2];
		tetrs->p2[1] = coord[3];
		tetrs->p3[0] = coord[4];
		tetrs->p3[1] = coord[5];
		tetrs->p4[0] = coord[6];
		tetrs->p4[1] = coord[7];
		tetrs->letter = letter;
		tetrs->next = NULL;
	}
	return (tetrs);
}

int			coord(char temp[4][5], t_tetr **full_tetrs, char letter)
{
	int		i;
	int		j;
	int		coord[8];
	int		cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (i <= 3)
	{
		while (temp[i][j] != '\0')
		{
			if (temp[i][j] == '#')
			{
				coord[cnt++] = i;
				coord[cnt++] = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (ft_lst_back(full_tetrs, make_list_tetramino(coord, letter)) == 0)
		delete_tetr(full_tetrs);
	return (0);
}

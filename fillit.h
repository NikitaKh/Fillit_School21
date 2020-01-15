/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:15:07 by spalmer           #+#    #+#             */
/*   Updated: 2019/11/30 21:14:14 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE1 21
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef	struct		s_tetr
{
	int				p1[2];
	int				p2[2];
	int				p3[2];
	int				p4[2];
	char			letter;
	struct s_tetr	*next;
}					t_tetr;
typedef	struct		s_map
{
	int				size;
	char			**map;
	char			letter;
}					t_map;

int					side_count(char *block);
int					char_count(char *block);
int					check_valid(char *block, int size);
int					full_line(char **line, char **ar, int fd);
int					check_temp(char *temp);
int					get_next_line(const int fd, char **line);
t_tetr				*make_list_tetramino(int *coord, char letter);
int					find_coord(char **temp);
void				print_struct(t_tetr *tetrs);
int					read_and_check(char *file);
int					count_tetra(char *file);
int					solve(t_tetr *full_tetrs, int size);
int					coord(char temp[4][5], t_tetr **full_tetrs, char letter);
int					ft_min_size(int cnt);
int					ft_list_len(t_tetr **tetrs);
int					size(char *file);
void				print_map(char **map, int size);
t_map				*fill_zero_map(t_map *map);
t_map				*make_map(int size);
t_map				*delete_map(t_map *map);
t_tetr				*reader(char *file);
int					change_coordinates_to_zero(int *coord);
void				delete_tetr(t_tetr **full_tetrs);
t_tetr				*reader_norm(int fd, char letter, int i, int j);
#endif

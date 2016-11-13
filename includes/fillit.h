/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:21:34 by jcapling          #+#    #+#             */
/*   Updated: 2016/11/12 03:32:36 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_map
{
	int				size;
	char			**str;
}					t_map;
typedef struct		s_cord
{
	int				x;
	int				y;
}					t_cord;
typedef struct		s_piece
{
	char			**place;
	int				width;
	int				height;
	char			value;
}					t_piece;

t_list				*reader(int fd);
int					tetri_check(char *str, int counter);
int					tetri_file(char *str);
t_piece				*get_block(char *str, char value);
void				end_values(char *str, t_cord *min, t_cord *max);
t_cord				*new_cord(int x, int y);
t_piece				*new_piece(char **place, int width, int height, char value);
t_list				*list_delete(t_list *list);
void				piece_delete(t_piece *piece);
void				delete_map(t_map *map);
void				map_print(t_map *map);
void				convert_piece(t_piece *piece, t_map *map, t_cord *cord, char c);
int					place_piece(t_piece *piece, t_map *map, int x, int y);
t_map				*create_map(int size);
t_map				*solver(t_list *list);
int					map_solver(t_map *map, t_list *list);
int					rnd_sqrt(int n);

#endif

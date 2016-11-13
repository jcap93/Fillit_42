/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 02:44:06 by jcapling          #+#    #+#             */
/*   Updated: 2016/11/12 19:29:52 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		delete_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->str[i]));
		i++;
	}
	ft_memdel((void **)&(map->str));
	ft_memdel((void **)&map);
}

void		map_print(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->str[i]);
		ft_putchar('\n');
		i++;
	}
}

void		convert_piece(t_piece *piece, t_map *map, t_cord *cord, char c)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (piece->place[j][i] == '#')
				map->str[cord->y + j][cord->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&cord);
}

int			place_piece(t_piece *piece, t_map *map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (piece->place[j][i] == '#' && map->str[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	convert_piece(piece, map, new_cord(x, y), piece->value);
	return (1);
}

t_map		*create_map(int size)
{
	t_map		*map;
	int			i;
	int			j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->str = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->str[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

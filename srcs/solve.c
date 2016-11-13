/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 03:09:09 by jcapling          #+#    #+#             */
/*   Updated: 2016/11/12 03:33:56 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*solver(t_list *list)
{
	t_map		*map;
	int			size;

	size = rnd_sqrt(ft_lstcount(list) * 4);
	map = create_map(size);
	while (!map_solver(map, list))
	{
		size++;
		delete_map(map);
		map = create_map(size);
	}
	return (map);
}

int			map_solver(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_piece		*piece;

	if (list == NULL)
		return (1);
	y = 0;
	piece = (t_piece *)(list->content);
	while (y < map->size - piece->height + 1)
	{
		x = 0;
		while (x < map->size - piece->width + 1)
		{
			if (place_piece(piece, map, x, y))
			{
				if (map_solver(map, list->next))
					return (1);
				else
					convert_piece(piece, map, new_cord(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int			rnd_sqrt(int n)
{
	int		size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 00:18:52 by jcapling          #+#    #+#             */
/*   Updated: 2016/11/12 01:31:07 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_cord		*new_cord(int x, int y)
{
	t_cord		*cord;

	cord = ft_memalloc(sizeof(t_cord));
	cord->x = x;
	cord->y = y;
	return (cord);
}

t_piece		*new_piece(char **place, int width, int height, char value)
{
	t_piece		*piece;

	piece = ft_memalloc(sizeof(t_piece));
	piece->place = place;
	piece->width = width;
	piece->height = height;
	piece->value = value;
	return (piece);
}

t_list		*list_delete(t_list *list)
{
	t_piece		*piece;
	t_list		*next;

	while (list)
	{
		piece = (t_piece *)list->content;
		next = list->next;
		piece_delete(piece);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void		piece_delete(t_piece *piece)
{
	int		y;

	y = 0;
	while (y < piece->height)
	{
		ft_memdel((void **)(&(piece->place[y])));
		y++;
	}
	ft_memdel((void **)(&(piece->place)));
	ft_memdel((void **)&piece);
}

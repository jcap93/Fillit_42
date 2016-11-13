/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:52:50 by jcapling          #+#    #+#             */
/*   Updated: 2016/11/12 03:05:30 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

t_list		*reader(int fd)
{
	char		*buf;
	int			i;
	t_list		*list;
	t_piece		*piece;
	char		c;

	buf = ft_strnew(21);
	list = NULL;
	c = 'A';
	while ((i = read(fd, buf, 21)) >= 20)
	{
		if (tetri_check(buf, i) != 0 || 
				(piece = get_block(buf, c++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return(list_delete(list));
		}
		ft_lstadd(&list, ft_lstnew(piece, sizeof(t_piece)));
		ft_memdel((void **)&piece);
	}
	ft_memdel((void **)&buf);
	if (i != 0)
		return (list_delete(list));
	ft_lstrev(&list);
	return (list);
}

// int			tetri_check(char *str, int counter)
// {
// 	int		i;
// 	int		piece;

// 	piece = 0;
// 	i = 0;
// 	while (i < 20)
// 	{
// 		if (i % 5 < 4)
// 		{
// 			if (!(str[i] == '#' || str[i] == '.'))
// 				return (1);
// 			if (str[i] == '#' && ++piece > 4)
// 				return (2);
// 		}
// 		else if (str[i] != '\n')
// 			return (3);
// 		i++;
// 	}
// 	if (counter == 21 && str[20] != '\n')
// 		return (4);
// 	if (!tetri_file(str))
// 		return (5);
// 	return (0);
// }

int			tetri_file(char *str)
{
	int		piece;
	int		i;

	piece = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				piece++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				piece++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				piece++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				piece++;
		}
		i++;
	}
	return (piece == 6 || piece == 8);
}

t_piece			*get_block(char *str, char value)
{
	t_cord		*min;
	t_cord		*max;
	char		**place;
	int			i;
	t_piece		*piece;

	min = new_cord(3, 3);
	max = new_cord(0, 0);
	end_values(str, min, max);
	place = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		place[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(place[i], str + (min->x) + (i + min->y) * 5, max->x - min->x + 1);
		i++;
	}
	piece = new_piece(place, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (piece);
}

void			end_values(char *str, t_cord *min, t_cord *max)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

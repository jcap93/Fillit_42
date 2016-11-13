/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:05:41 by jcapling          #+#    #+#             */
/*   Updated: 2016/11/12 19:29:32 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "fillit.h"

int			main(int ac, char **av)
{
	t_list		*list;
	t_map		*map;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((list = reader(open(av[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map = solver(list);
	map_print(map);
	delete_map(map);
	list_delete(list);
	return (0);
}

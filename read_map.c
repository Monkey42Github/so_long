/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:59:48 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/07 15:09:28 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map_file(char *file, t_data	*d)
{
	char	**map;
	int		fd;
	int		i;

	map = malloc_map(file, d);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < d->h)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**malloc_map(char *file, t_data	*d)
{
	char	**map;
	char	*str;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		i++;
	}
	d->h = i;
	map = malloc(sizeof(char *) * (i + 1));
	close(fd);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:26:28 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/18 17:38:49 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collect_map(t_map *map, char *filename, int height, int width)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	map->map = malloc(sizeof(char *) * (height + 1));
	if (!map->map)
		return (ERROR);
	while (i < height)
	{
		line = get_next_line(fd);
		map->map[i] = malloc(sizeof(char) * (width + 1));
		if (!map->map[i])
			return (ERROR);
		line = ft_strtrim(line, "\n");
		map->map[i] = line;
		free(line);
		i++;
	}
	if (close(fd) == -1)
		return (ft_putstr_fd("Couldn't close fd in collect_map\n", 2), ERROR);
	return (SUCCESS);
}


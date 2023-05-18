/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:04:31 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/18 15:37:03 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	line_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1')
			i++;
		else
		{
			ft_putstr_fd("Map isn't enclosed by walls\n", 2);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

static int	check_extremities(char *line)
{
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
	{
		ft_putstr_fd("Map isn't enclosed by walls\n", 2);
		return (ERROR);
	}
}

int	check_walls(char *filename, t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (++i < map->height)
	{
		line = get_next_line(fd);
		if (i == 0 || i == map->height - 1)
			if (line_wall(line) == ERROR)
				return (ERROR);
		if (i != 0 && i != map->width - 1)
			if (check_extremities(line) == ERROR)
				return (ERROR);
	}
	if (close(fd) == -1)
		return (ft_putchar_fd("Fail to close fd in check_walls", 2), ERROR);
	return (SUCCESS);
}

int	base_len(char *filename)
{
	int		len;
	int		fd;
	char	*line;
 
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	if (line[0] == '\n')
		exit(EXIT_FAILURE);
	len = (int)ft_strlen(line) - 1;
	close(fd);
	return (len);
}

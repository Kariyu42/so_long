/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:26:28 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/19 17:02:40 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to be deleted
void	print_map(char *str)
{
	int	i	= -1;
	while (str[++i])
		write(1, &str[i], 1);
}

static int	check_paths(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		
		i++;
	}
	return (SUCCESS);
}

static int	search_char(char *line, t_map *map)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (ft_strchr("10PCE", line[i]) == 0)
			return (ft_putstr_fd("found abnormal char in map", 2), ERROR);
		if (line[i] == 'E')
			map->tools.door += 1;
		else if (line[i] == 'P')
			map->tools.player += 1;
		else if (line[i] == 'C')
			map->tools.collects += 1;
	}
	if (map->tools.door == 1 && map->tools.collects > 0 \
		&& map->tools.player == 1)
		return (SUCCESS);
	return (ERROR);
}

int	check_adds_map(t_map *map, int width)
{
	// check length of each line to see if its rectangle
	int	i;

	i = 0;
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) - 1 != width)
			return (ft_putstr_fd("map not a rectangle\n", 2), ERROR);
		if (search_char(map->map[i], map) == ERROR)
			return (ERROR);
		i++;
	}
	if (check_paths(map) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	collect_map(t_map *map, char *filename, int height, int width)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	map->map = malloc(sizeof(char *) * (height + 1));
	if (!map->map)
		return (ERROR);
	while (++i < height)
	{
		line = get_next_line(fd);
		map->map[i] = malloc(sizeof(char) * (width + 1));
		if (!map->map[i])
			return (ERROR);
		line = ft_strtrim(line, "\n");
		map->map[i] = line;
		//print_map(map->map[i]);
		free(line);
	}
	map->map[i] = NULL;
	if (close(fd) == -1)
		return (ft_putstr_fd("Couldn't close fd: collect_map\n", 2), ERROR);
	return (SUCCESS);
}

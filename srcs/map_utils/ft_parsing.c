/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:26:28 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/22 17:30:52 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	search_char(char *line, t_map *map)
{
	int	i;

	i = -1;
	puts("search_char");
	while (line[++i] && i < map->width)
	{
		if (ft_strchr("10PCE", line[i]) == 0)
		{
			printf("line[%d] : %c\n", i, line[i]);
			return (ft_putstr_fd("found abnormal char in map\n", 2), ERROR);
		}
		if (line[i] == 'E')
			map->tools.door += 1;
		else if (line[i] == 'P')
			map->tools.player += 1;
		else if (line[i] == 'C')
			map->tools.collects += 1;
	}
	return (SUCCESS);
}

t_start	find_start(char player, char **map)
{
	int	i;
	int	j;
	t_start	pos;

	i = 0;
	j = 0;
	pos.x = 0;
	pos.y = 0;
	puts("find_start");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == player)
			{
				pos.x = j;
				pos.y = i;
				printf("player position: x:%d y:%d\n", pos.x, pos.y);
				return (pos);
			}
			j++;
		}
		i++;
	}
	ft_putstr_fd("could not find player\n", 2);
	exit(EXIT_FAILURE);
}

void	check_paths(t_map *map, t_start pos, char *fill)
{
	static int	c = 0;
	static int	e = 0;

	if (pos.x <= 0 || pos.y <= 0 \
		|| !ft_strchr(fill, map->map[pos.y][pos.x]))
		return ;
	if (map->map[pos.y][pos.x] == 'C')
		c += 1;
	else if (map->map[pos.y][pos.x] == 'E')
		e += 1;
	map->map[pos.y][pos.x] = 'X';
	check_paths(map, (t_start){pos.x - 1, pos.y}, fill);
	check_paths(map, (t_start){pos.x, pos.y + 1}, fill);
	check_paths(map, (t_start){pos.x + 1, pos.y}, fill);
	check_paths(map, (t_start){pos.x, pos.y - 1}, fill);
	if (c != map->tools.collects || c == 0)
		return (ft_putstr_fd("No access to all collectibles\n", 2));
	if (e != map->tools.door || e == 0)
		return (ft_putstr_fd("No access to the door", 2));
}

int	check_adds_map(t_map *map, int width)
{
	// check length of each line to see if its a rectangle
	// check incorrect characters
	// check if its enclosed by walls
	int	i;

	i = 0;
	print_map(map);
	while (map->map[i] && i < map->height)
	{
		if ((int)ft_strlen(map->map[i]) - 1 != width)
			return(ft_putstr_fd("Map not rectangle!\n", 2), ERROR);
		if (check_walls(map->map[i], i, map, width) == ERROR)
			return (ft_putstr_fd("Not closed map\n", 2), ERROR);
		if (search_char(map->map[i], map) == ERROR)
			return (ft_putstr_fd("Char problem\n", 2), ERROR);
		i++;
	}
	if (map->tools.door == 1 && map->tools.collects > 0 \
		&& map->tools.player == 1)
		{
			check_paths(map, find_start('P', map->map), "0CE");
			print_map(map);
			return (SUCCESS);
		}
	ft_putstr_fd("An error was found: Please check the map format\n", 2);
	return (ERROR);
}

int	collect_map(t_map *map, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	map->height = get_map_height(filename);
	printf("map->height : %d\n", map->height);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	map->map = ft_calloc(sizeof(char *), map->height + 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		// printf("BEFORE TRIM = %s", line);
		map->map[i] = ft_strtrim(line, "\n");
		free(line);
		// printf("AFTER TRIM = %s", map->map[i]);
		i++;
	}
	close(fd);
	return (SUCCESS);
}

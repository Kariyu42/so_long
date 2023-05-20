/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:26:28 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/20 16:41:17 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to be deleted
void	print_map(char *str)
{
	int	i	= -1;
	while (str[++i])
		write(1, &str[i], 1);
	printf("\n");
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
	if (map->tools.door > 1)
		ft_putstr_fd("Too many doors\n", 2);
	return (ERROR);
}

t_start	find_start(char player, char **map)
{
	int	i;
	int	j;
	t_start	pos;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j = 0;
			if (map[i][j] == player)
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	ft_putstr_fd("could not find player\n", 2);
	exit(EXIT_FAILURE);
}

static void	check_paths(t_map *map, t_start pos, char *fill)
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
	int		i;

	i = 0;
	while (map->map[i])
	{
		if (check_walls(map->map[i], i, map, width) == ERROR)
			return (ERROR);
		if ((int)ft_strlen(map->map[i]) - 1 != width)
			return (ft_putstr_fd("map not a rectangle\n", 2), ERROR);
		if (search_char(map->map[i], map) == ERROR)
			return (ERROR);
		i++;
	}
	check_paths(map, find_start('P', map->map), "0CE");
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
	puts("aaa");
	while (++i < height)
	{
		line = get_next_line(fd);
		printf("\nline = %s\n", line);
		map->map[i] = malloc(sizeof(char) * (width + 1));
		if (!map->map[i])
			return (ERROR);
		line = trim_newline(line);
		printf("line : %s\n", line);
		map->map[i] = line;
		print_map(map->map[i]);
		printf("i : %d\n", i);
		free(line);
	}
	map->map[i] = NULL;
	if (close(fd) == -1)
		return (ft_putstr_fd("Couldn't close fd: collect_map\n", 2), ERROR);
	return (SUCCESS);
}

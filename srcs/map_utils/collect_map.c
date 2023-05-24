/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:26:28 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/24 10:49:50 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_start	find_start(char player, char **map)
{
	int	i;
	int	j;
	t_start	pos;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == player)
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
		}
	}
	exit(EXIT_FAILURE);
}

static void	check_paths(char **plan, t_start pos, t_map *map)
{
	static int	c = 0;
	static int	e = 0;

	if (pos.x <= 0 || pos.y <= 0 \
		|| plan[pos.y][pos.x] == '1' || plan[pos.y][pos.x] == 'X')
		return ;
	if (plan[pos.y][pos.x] == 'C')
		c += 1;
	else if (plan[pos.y][pos.x] == 'E')
		e += 1;
	plan[pos.y][pos.x] = 'X';
	check_paths(plan, (t_start){pos.x + 1, pos.y}, map);
	check_paths(plan, (t_start){pos.x - 1, pos.y}, map);
	check_paths(plan, (t_start){pos.x, pos.y + 1}, map);
	check_paths(plan, (t_start){pos.x, pos.y - 1}, map);
	if (c != map->tools.collects || c == 0)
		ft_error(6);
	if (e != map->tools.door || e == 0)
		ft_error(7);
}

static int	parsing_check(t_map *map, int width)
{
	int	i;

	i = 0;
	//print_map(map); // remove function before push !
	while (map->map[i])
	{
		if (check_walls(map->map[i], i, map, width) == ERROR)
			return (ft_putstr_fd("Not closed map\n", 2), ERROR);
		if ((int)ft_strlen(map->map[i]) != width)
			return(ft_putstr_fd("Map not rectangle!\n", 2), ERROR);
		if (search_char(map->map[i], map) == ERROR)
			return (ft_putstr_fd("Char problem\n", 2), ERROR);
		i++;
	}
	if (map->tools.door == 1 && map->tools.collects > 0 \
		&& map->tools.player == 1)
		{
			check_paths(map_dup(map->map, map), find_start('P', map->map), map);
			print_map(map); // remove function before push !
			return (SUCCESS);
		}
	ft_putstr_fd("An error was found: Please check the map format\n", 2);
	return (ERROR);
}

static int	parse_map(t_map *map, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error(5));
	map->map = ft_calloc(sizeof(char *), map->height + 1);
	if (!map->map)
		return (ERROR);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->map[i] = trim_newline(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (SUCCESS);
}

void	collect_map(char *filename, t_map *map)
{
	init_params(map);
	printf("IN COLLECT MAP\n"); // remove printf before push !
	map->height = get_map_height(filename);
	printf("map->height : %d\n", map->height); // remove printf before push !
	if (parse_map(map, filename) == ERROR)
		exit(EXIT_FAILURE);
	// print_map(map); // remvore function before push !
	map->width = (int)ft_strlen(map->map[0]);
	printf("map->width : %d\n", map->width);
	if (parsing_check(map, map->width) == ERROR)
		exit(EXIT_FAILURE);
}

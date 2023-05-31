/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:26:28 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/31 10:24:54 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_start	find_start(char player, char **map)
{
	int		i;
	int		j;
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

static void	check_paths(char **plan, t_start pos, t_game *game, char *to_fill)
{
	if (pos.x <= 0 || pos.y <= 0 \
		|| plan[pos.y][pos.x] == '1' || !ft_strchr(to_fill, plan[pos.y][pos.x]))
		return ;
	if (plan[pos.y][pos.x] == 'C')
		game->flood_c += 1;
	else if (plan[pos.y][pos.x] == 'E')
		game->flood_e += 1;
	plan[pos.y][pos.x] = 'X';
	check_paths(plan, (t_start){pos.x - 1, pos.y}, game, to_fill);
	check_paths(plan, (t_start){pos.x + 1, pos.y}, game, to_fill);
	check_paths(plan, (t_start){pos.x, pos.y - 1}, game, to_fill);
	check_paths(plan, (t_start){pos.x, pos.y + 1}, game, to_fill);
}

static int	parsing_check(t_game *game, int width)
{
	int		i;
	char	**tmp;

	i = 0;
	while (game->map.map[i])
	{
		if (check_walls(game->map.map[i], i, game, width) == ERROR)
			return (ft_putstr_fd("Error\nNot closed map\n", 2), ERROR);
		if ((int)ft_strlen(game->map.map[i]) != width)
			return (ft_putstr_fd("Error\nMap not rectangle!\n", 2), ERROR);
		if (search_char(game->map.map[i], game) == ERROR)
			return (ft_putstr_fd("Error\nChar problem\n", 2), ERROR);
		i++;
	}
	if (game->map.tools.door == 1 && game->map.tools.collects > 0 \
		&& game->map.tools.player == 1)
	{
		tmp = map_dup(game->map.map, game);
		check_paths(tmp, find_start('P', game->map.map), game, "P0CE");
		free_map(tmp);
		return (SUCCESS);
	}
	ft_putstr_fd("Error\nPlease check the map format\n", 2);
	return (ERROR);
}

static int	parse_map(t_game *game, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error(5));
	game->map.map = ft_calloc(sizeof(char *), game->map.height + 1);
	if (!game->map.map)
		return (ERROR);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map.map[i] = trim_newline(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (SUCCESS);
}

void	collect_map(char *filename, t_game *game)
{
	init_params(game);
	game->map.height = get_map_height(filename);
	if (!game->map.height)
	{
		ft_error(4);
		exit(EXIT_FAILURE);
	}
	if (parse_map(game, filename) == ERROR)
		exit(EXIT_FAILURE);
	game->map.width = (int)ft_strlen(game->map.map[0]);
	if (!game->map.width)
	{
		ft_error(4);
		exit(EXIT_FAILURE);
	}
	if (parsing_check(game, game->map.width) == ERROR)
		exit(EXIT_FAILURE);
	if (game->flood_c != game->map.tools.collects)
		ft_error(6);
	if (game->flood_e != game->map.tools.door)
		ft_error(7);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:28:17 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/31 10:26:24 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_start	find_pos(char player, char **map)
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
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

static void	check_move(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	else if (map[y][x] == 'C')
		game->map.tools.collects -= 1;
	else if (map[y][x] == 'E')
	{
		if (game->map.tools.collects == 0)
			exit(EXIT_SUCCESS);
		else
		{
			game->map.map[y][x] = 'X';
			w_img(game, game->map.v.player, x * 64, y * 64);
			game->valid_path = 1;
			return ;
		}
	}
	game->valid_path = 1;
	game->map.map[y][x] = 'P';
	w_img(game, game->map.v.player, x * 64, y * 64);
}

static void	move_player2(t_game *game, t_start player, int var)
{
	if (var && game->valid_path != 0)
	{
		game->map.map[player.y][player.x] = 'E';
		w_img(game, game->map.v.ground, player.x * 64, player.y * 64);
		w_img(game, game->map.v.exit, player.x * 64, player.y * 64);
		var = 0;
	}
	else if (game->valid_path != 0 && !var)
	{
		game->map.map[player.y][player.x] = '0';
		w_img(game, game->map.v.ground, player.x * 64, player.y * 64);
	}
}

void	move_player(t_game *game, int dir)
{
	int		var;
	t_start	player;

	var = 0;
	game->valid_path = 0;
	player = find_pos('P', game->map.map);
	if (player.x == -1 && player.y == -1 && !var)
	{
		player = find_pos('X', game->map.map);
		var = 1;
	}
	if (dir == MOVE_L)
		check_move(game, game->map.map, player.x - 1, player.y);
	else if (dir == MOVE_R)
		check_move(game, game->map.map, player.x + 1, player.y);
	else if (dir == MOVE_UP)
		check_move(game, game->map.map, player.x, player.y - 1);
	else if (dir == MOVE_D)
		check_move(game, game->map.map, player.x, player.y + 1);
	move_player2(game, player, var);
	if (game->valid_path)
	{
		game->moves++;
		ft_printf("MOVES: %d\n", game->moves);
	}
}

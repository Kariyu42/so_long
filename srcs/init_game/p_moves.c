/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:28:17 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/29 18:14:07 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// used for the player's moves when pressing a key
// if the player is on a collectible, it will be removed
// if the player is on the exit, and that all collectibles are collected, the game will end
// else if the player is on the exit, and that all collectibles are not collected, nothing will happen
// if the player is trying to move on a wall, nothing will happen

// The way it works is that we will print the player in the new position, and then print the ground in the old position
// This way, the player will be moved

static void	check_move(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		game->map.tools.collects -= 1;
	if (map[y][x] == 'E' && game->map.tools.collects == 0)
		exit(EXIT_SUCCESS);
	game->map.map[y][x] = 'P';
	w_img(game, game->map.v.player, x * 64, y * 64);
}

void	move_player(t_game *game, int dir)
{
	t_start	pos;

	game->player = find_start('P', game->map.map);
	pos = game->player;
	if (dir == MOVE_UP)
		check_move(game, game->map.map, pos.x, pos.y - 1);
	else if (dir == MOVE_D)
		check_move(game, game->map.map, pos.x, pos.y + 1);
	else if (dir == MOVE_L)
		check_move(game, game->map.map, pos.x - 1, pos.y);
	else if (dir == MOVE_R)
		check_move(game, game->map.map, pos.x + 1, pos.y);
	if (game->map.map[pos.y][pos.x] != 'E')
	{
		game->map.map[pos.y][pos.x] = '0';
		w_img(game, game->map.v.ground, pos.x * 64, pos.y * 64);
	}
}

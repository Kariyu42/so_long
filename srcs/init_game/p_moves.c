/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:28:17 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/29 12:17:20 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// used for the player's moves when pressing a key
// if the player is on a collectible, it will be removed
// if the player is on the exit, and that all collectibles are collected, the game will end
// else if the player is on the exit, and that all collectibles are not collected, nothing will happen
// if the player is trying to move on a wall, nothing will happen

// The way it works is that we will print the player in the new postion, and then print the ground in the old position
// This way, the player will be moved

void	move_player(t_game *game, int dir)
{
	t_start	pos;

	game->player = find_start('P', game->map.map);
	pos = game->player;
	if (dir == MOVE_UP)
		check_move();
	else if (dir == MOVE_R)
		
	else if (dir == MOVE_L)
		
	else if (dir == MOVE_D)
		
	game->map.map[pos.y][pos.x] = '0';
}

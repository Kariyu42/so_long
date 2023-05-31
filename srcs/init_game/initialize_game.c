/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:01:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/31 10:25:29 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx_win(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (game->mlx.mlx == NULL)
		exit(EXIT_FAILURE);
	game->mlx.win = mlx_new_window(game->mlx.mlx, game->map.width * 64, \
		game->map.height * 64, "kquetat- SO_LONG");
	if (game->mlx.win == NULL)
		exit(EXIT_FAILURE);
	game->mlx.img = mlx_new_image(game->mlx.mlx, game->map.width * 64, \
		game->map.width * 64);
	if (game->mlx.img == NULL)
		exit(EXIT_FAILURE);
}

static void	stash_filenames(t_game *game)
{
	game->map.v.width = 64;
	game->map.v.height = 64;
	game->map.v.wall = mlx_xpm_file_to_image(game->mlx.mlx, \
		"./img/wall_tree.xpm", &game->map.v.width, &game->map.v.height);
	game->map.v.exit = mlx_xpm_file_to_image(game->mlx.mlx, \
		"./img/exit_front.xpm", &game->map.v.width, &game->map.v.height);
	game->map.v.coin = mlx_xpm_file_to_image(game->mlx.mlx, \
		"./img/collectible.xpm", &game->map.v.width, &game->map.v.height);
	game->map.v.ground = mlx_xpm_file_to_image(game->mlx.mlx, \
		"./img/basic_grass.xpm", &game->map.v.width, &game->map.v.height);
	game->map.v.player = mlx_xpm_file_to_image(game->mlx.mlx, \
		"./img/player_front.xpm", &game->map.v.width, &game->map.v.height);
}

void	put_images(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (g->map.map[++i])
	{
		j = -1;
		while (g->map.map[i][++j])
		{
			w_img(g, g->map.v.ground, j * 64, i * 64);
			if (g->map.map[i][j] == 'P')
				w_img(g, g->map.v.player, j * 64, i * 64);
			else if (g->map.map[i][j] == '1')
				w_img(g, g->map.v.wall, j * 64, i * 64);
			else if (g->map.map[i][j] == 'C')
				w_img(g, g->map.v.coin, j * 64, i * 64);
			else if (g->map.map[i][j] == 'E')
				w_img(g, g->map.v.exit, j * 64, i * 64);
		}
	}
}

static int	key_press(int keycode, t_game *game)
{
	if (keycode == MOVE_UP)
		move_player(game, MOVE_UP);
	else if (keycode == MOVE_D)
		move_player(game, MOVE_D);
	else if (keycode == MOVE_L)
		move_player(game, MOVE_L);
	else if (keycode == MOVE_R)
		move_player(game, MOVE_R);
	else if (keycode == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

void	initialize_game(t_game *game)
{
	init_mlx_win(game);
	stash_filenames(game);
	put_images(game);
	game->moves = 0;
	mlx_hook(game->mlx.win, RED_CROSS, 1L << 17, &close_win, game);
	mlx_key_hook(game->mlx.win, &key_press, game);
	mlx_loop(game->mlx.mlx);
}

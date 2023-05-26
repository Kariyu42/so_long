/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:01:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/26 18:07:31 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx_win(t_mlx *mlx, t_map *map)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit(EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->mlx, map->width * 64, map->height * 64, \
		"kquetat- SO_LONG");
	if (mlx->win == NULL)
		exit(EXIT_FAILURE);
	mlx->img = mlx_new_image(mlx->mlx, map->width * 64, map->width * 64);
	if (mlx->img == NULL)
		exit(EXIT_FAILURE);
}

static void	stash_filenames(t_map *map, t_mlx *mlx)
{
	map->v.width = 64;
	map->v.height = 64;
	map->v.wall = mlx_xpm_file_to_image(mlx->mlx, "./img/wall_tree.xpm", \
		&map->v.width, &map->v.height);
	map->v.exit = mlx_xpm_file_to_image(mlx->mlx, "./img/exit_front.xpm", \
		&map->v.width, &map->v.height);
	map->v.coin = mlx_xpm_file_to_image(mlx->mlx, "./img/collectible.xpm", \
		&map->v.width, &map->v.height);
	map->v.ground = mlx_xpm_file_to_image(mlx->mlx, "./img/basic_grass.xpm", \
		&map->v.width, &map->v.height);
	map->v.player = mlx_xpm_file_to_image(mlx->mlx, "./img/player_front.xpm", \
		&map->v.width, &map->v.height);
}

static void	put_images(t_map *map, t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, map->v.ground, j * 64, i * 64);
			if (map->map[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, map->v.player, j * 64, i * 64);
			else if (map->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, map->v.wall, j * 64, i * 64);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, map->v.coin, j * 64, i * 64);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, map->v.exit, j * 64, i * 64);
		}
	}
}

/*void	render(t_map *map, t_mlx *mlx)
{
	int	i;
	int	j;
	t_start	player;

	i = -1;
	player = find_start('P', map->map);
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j] && )
		{
			
		}
	}
}*/

static int	hook_func(int keycode, t_mlx *mlx)
{
	if (keycode == 2)
		
	// A = 0;
	// W = 13;
	// S = 1;
	// D = 2;
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	initialize_game(t_map *map, t_mlx *mlx)
{
	init_mlx_win(mlx, map);
	stash_filenames(map, mlx);
	put_images(map, mlx);
//	render(map, mlx);
	mlx_hook(mlx->win, RED_CROSS, 1L << 17, &close_win, mlx);
	mlx_key_hook(mlx->win, &hook_func, mlx);
	mlx_loop(mlx->mlx);
}

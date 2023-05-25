/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:01:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/25 13:13:15 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx_win(t_mlx *mlx, t_data *img, t_map *map)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit(EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->mlx, map->width * 64, map->height * 64, \
		"kquetat- SO_LONG");
	if (mlx->win == NULL)
		exit(EXIT_FAILURE);
	img->img = mlx_new_image(mlx->mlx, map->width * 64, map->height * 64);
	if (img->img == NULL)
		exit(EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (img->addr == NULL)
		exit(EXIT_FAILURE);
}

/*static void	put_images(t_map *map, t_mlx *mlx, t_data *img)
{
	
}*/

void	initialize_game(t_map *map, t_mlx *mlx, t_data *img)
{
	init_mlx_win(mlx, img, map);
	put_images();
	mlx_hook(mlx->win, RED_CROSS, 1L << 17, &close_win, mlx);
	mlx_key_hook(mlx->win, &key_exit, mlx);
	mlx_loop(mlx->mlx);
}

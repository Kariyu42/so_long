/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:01:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/24 14:42:01 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx_win(t_mlx *mlx, t_data *img)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit(EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "kquetat- SO_LONG");
	if (mlx->win == NULL)
		exit(EXIT_FAILURE);
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
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
	(void)map;
	init_mlx_win(mlx, img);
	//put_images();
	mlx_hook(mlx->win, RED_CROSS, 1L << 17, &close_win, mlx);
	mlx_key_hook(mlx->win, &key_exit, mlx);
	mlx_loop(mlx->mlx);
}

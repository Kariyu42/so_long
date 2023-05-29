/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:07:50 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/29 14:54:04 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_img(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx.mlx, g->mlx.win, img, x, y);
}

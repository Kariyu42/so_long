/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:19:43 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/29 10:40:23 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	exit(EXIT_SUCCESS);
	return (0);
}

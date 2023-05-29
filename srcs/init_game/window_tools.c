/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:19:43 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/29 15:29:59 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit_game(t_game *game)
{
	free_map(game->map.map);
	exit(EXIT_SUCCESS);
}

int	close_win(void)
{
	//mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	exit(EXIT_SUCCESS);
	return (0);
}

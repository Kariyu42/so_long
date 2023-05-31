/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:16:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/31 09:58:09 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_params(t_game *game)
{
	game->flood_c = 0;
	game->flood_e = 0;
	game->map.width = 0;
	game->map.height = 0;
	game->map.tools.door = 0;
	game->map.tools.player = 0;
	game->map.tools.collects = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_error(2));
	if (check_extension(argv[1]) == ERROR)
		return (ft_error(3));
	collect_map(argv[1], &game);
	initialize_game(&game);
	return (0);
}

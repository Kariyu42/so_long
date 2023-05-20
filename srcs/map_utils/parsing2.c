/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:39:43 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/20 15:52:21 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char *line, int index, t_map *map, int width)
{
	int	i;

	i = 0;
	if (index == 0 || index == map->height)
	{
		while (line[i])
		{
			if (line[i] != '1')
				return (ERROR);
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[width] != '1')
			return (ERROR);
	}
	return (SUCCESS);
}

char	*trim_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	line[i] = '\0';
	return (line);
}

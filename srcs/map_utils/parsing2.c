/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:39:43 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/22 15:52:01 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
check if its well enclosed by walls
*/

int	check_walls(char *line, int index, t_map *map, int width)
{
	int	i;

	i = 0;
	puts("check_walls");
	printf("%s\nindex: %d\n", line, index);
	if (index == 0 || index == map->height)
	{
		while (line[i] && i < width)
		{
			if (line[i] != '1')
			{
				printf("line[%d]: %c\n", i, line[i]);
				puts("start or end of map");
				return (ERROR);
			}
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[width] != '1')
		{
			puts("middle part of map");
			return (ERROR);
		}
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

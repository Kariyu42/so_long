/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:35:34 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/24 10:40:44 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function that creates a copy of the map
char	**map_dup(char **plan, t_map *map)
{
	int		i;
	char	**copy;

	i = -1;
	copy = ft_calloc(sizeof(char *), map->height + 1);
	while (plan[++i])
		copy[i] = ft_strdup(plan[i]);
	return (copy);
}

int	search_char(char *line, t_map *map)
{
	int	i;

	i = -1;
	//puts("search_char"); // remove puts(); before push
	while (line[++i] && i < map->width)
	{
		if (ft_strchr("10PCE", line[i]) == 0)
			return (ft_putstr_fd("found abnormal char in map\n", 2), ERROR);
		if (line[i] == 'E')
			map->tools.door += 1;
		else if (line[i] == 'P')
			map->tools.player += 1;
		else if (line[i] == 'C')
			map->tools.collects += 1;
	}
	return (SUCCESS);
}

int	check_walls(char *line, int index, t_map *map, int width)
{
	int	i;

	i = 0;
	//puts("check_walls"); // remove puts before push !
	//printf("%s\nindex: %d\n", line, index); // remove printf before push !
	if (index == 0 || index == map->height)
	{
		while (line[i])
		{
			if (line[i] != '1')
			{
				//printf("line[%d]: %c\n", i, line[i]);
				return (puts("start or end of map"), ERROR);
			}
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[width - 1] != '1')
			return (puts("middle part of map"), ERROR);
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

int	get_map_height(char *filename)
{
	int		fd;
	int		len;
	char	*line;

	len = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error(5));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len++;
		free(line);
	}
	close(fd);
	return (len);
}

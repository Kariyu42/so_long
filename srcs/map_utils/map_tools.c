/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:35:34 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/31 14:21:05 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_dup(char **plan, t_game *game)
{
	int		i;
	char	**copy;

	i = -1;
	copy = ft_calloc(sizeof(char *), game->map.height + 1);
	while (plan[++i])
		copy[i] = ft_strdup(plan[i]);
	return (copy);
}

int	search_char(char *line, t_game *game)
{
	int	i;

	i = -1;
	while (line[++i] && i < game->map.width)
	{
		if (ft_strchr("10PCE", line[i]) == 0)
			return (ERROR);
		if (line[i] == 'E')
			game->map.tools.door += 1;
		else if (line[i] == 'P')
			game->map.tools.player += 1;
		else if (line[i] == 'C')
			game->map.tools.collects += 1;
	}
	return (SUCCESS);
}

int	check_walls(char *line, int index, t_game *game, int width)
{
	int	i;

	i = 0;
	if (index == 0 || index == game->map.height - 1)
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
		if (line[0] != '1' || line[width - 1] != '1')
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

int	get_map_height(char *filename)
{
	int		fd;
	int		len;
	char	*line;

	len = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (ft_error(5));
		exit(EXIT_FAILURE);
	}
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

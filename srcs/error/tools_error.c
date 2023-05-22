/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:27:10 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/22 11:19:44 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char *filename)
{
	int		fd;
	int		len;
	char	*line;

	len = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		len++;
		free(line);
	}
	close(fd);
	if (len < 3)
	{
		ft_putstr_fd("map not big enough\n", 2);
		exit(EXIT_FAILURE);
	}
	return (len);
}

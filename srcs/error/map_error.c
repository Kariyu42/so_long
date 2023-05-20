/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:04:31 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/20 15:04:25 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	base_len(char *filename)
{
	int		len;
	int		fd;
	char	*line;
 
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	if (line[0] == '\n')
		exit(EXIT_FAILURE);
	len = (int)ft_strlen(line) - 2;
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	return (len);
}

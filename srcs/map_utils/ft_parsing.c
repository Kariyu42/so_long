/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:26:28 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/15 16:06:24 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Here we will check all the errors listed on main
if no errors are found, we will return SUCCESS.
*/
/*static char	*get_line(char *line, t_map *map)
{
	int	i;
}*/

/*static int	collect_map(char *filename, t_map *map)
{
	
}*/

int	collect_map(t_map **map, char *filename, int height, int width)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while (i < height)
	{
		
		i++;
	}
}


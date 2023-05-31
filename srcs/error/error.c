/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:46:46 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/31 14:18:46 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_extension(char *str)
{
	int			i;
	const char	*ext;
	int			len_ext;
	int			len_filename;

	ext = ".ber";
	len_ext = (int)ft_strlen(ext);
	len_filename = (int)ft_strlen(str);
	if (len_filename <= len_ext)
		return (ERROR);
	i = len_filename - len_ext;
	if (!ft_strncmp(str + i, ext, ft_strlen(str + i)))
		return (SUCCESS);
	return (ERROR);
}

int	ft_error(int error)
{
	ft_printf("Error\n");
	if (error == 2)
		ft_putstr_fd("Wrong number of arguments!\n", 2);
	else if (error == 3)
		ft_putstr_fd("Not a .ber extension file!\n", 2);
	else if (error == 4)
		ft_putstr_fd("Map error format!\n", 2);
	else if (error == 5)
		ft_putstr_fd("Failed to open file\n", 2);
	else if (error == 6)
	{
		ft_putstr_fd("No access to all collectibles\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (error == 7)
	{
		ft_putstr_fd("No access to the door\n", 2);
		exit(EXIT_FAILURE);
	}
	return (ERROR);
}

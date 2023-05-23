/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:46:46 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/23 15:39:49 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	i++;
	if (str[i] == 'b' && str[i + 1] == 'e' && str[i + 2] == 'r'
		&& str[i + 3] == '\0')
		return (SUCCESS);
	return (ERROR);
}

int	ft_error(int error)
{
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

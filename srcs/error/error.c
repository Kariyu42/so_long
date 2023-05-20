/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:46:46 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/20 16:39:35 by kquetat-         ###   ########.fr       */
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
	if (error == ERROR)
		ft_putstr_fd("Wrong number of arguments!\n", 2);
	return (ERROR);
}

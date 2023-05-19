/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/19 16:00:55 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERROR 1
# define SUCCESS 0

/* mlx window size */
# define WIDTH 1920
# define HEIGHT 1080

/*
- tools for checking the data in map
*/
typedef struct s_tools
{
	int	player;
	int	collects;
	int	door;
}				t_tools;

/* struct pour la map a parser qui contient :
** - un tableau de char **map
** - un int width qui contient la largeur de la map // nous servira pour la vérification de la map rectangulaire
*/
typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
	t_tools	tools;
}				t_map;

/* s_data pour la mlx qui contient :
** - un void *img
** - un char *addr
** - un int bits_per_pixel
** - un int line_length
** - un int endian
*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* struct pour la mlx qui contient :
** - un void *mlx
** - un void *win
*/
typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

/**** libraries ****/
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/inc/libft.h"

/** Map Parsing **/
int	get_map_height(char *filename);
int	check_adds_map(t_map *map, int width);
int	base_len(char *filename);
int	collect_map(t_map *map, char *filename, int height, int width);

/** Error functions **/
int		ft_error(int error);
int		check_extension(char *str);
void	rectangular_map(char *filename, t_map *map);
int		check_walls(char *filename, t_map *map);

#endif

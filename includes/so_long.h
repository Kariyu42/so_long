/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/24 10:44:31 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERROR 1
# define SUCCESS 0

/* mlx window size */
# define WIDTH 1920
# define HEIGHT 1080

// starting pont for flood_fill function : check_paths();
typedef struct	s_start
{
	int	x;
	int	y;
}				t_start;

typedef struct	s_tools
{
	int	door;
	int	player;
	int	collects;
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

typedef struct	s_data
{
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

/** Initialize parameters **/
void	init_params(t_map *map);

// Map Parsing
char	*trim_newline(char *line);
int		get_map_height(char *filename);
char	**map_dup(char **plan, t_map *map);
int		search_char(char *line, t_map *map);
void	collect_map(char *filename, t_map *map);
int		check_walls(char *line, int index, t_map *map, int width);

// Free map function
void	free_map(char **plan);

/** Print & error functions **/
int		ft_error(int error);
int		check_extension(char *str);

/* remove this function before push */
void	print_map(t_map *map);

#endif

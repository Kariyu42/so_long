/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/22 12:08:06 by kquetat-         ###   ########.fr       */
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

/** Map Parsing **/
int		get_map_height(char *filename);
int		check_adds_map(t_map *map, int width);
int		base_len(char *filename);
int		collect_map(t_map *map, char *filename);
char	*trim_newline(char *line);
int		check_walls(char *line, int index, t_map *map, int width);

/** Error functions **/
int		ft_error(int error);
int		check_extension(char *str);
void	print_map(t_map *map);

#endif

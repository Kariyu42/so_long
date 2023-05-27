/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/27 15:27:18 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// General
# define ERROR -1
# define SUCCESS 0

// Player move
# define MOVE_UP 13
# define MOVE_D 1
# define MOVE_L 0
# define MOVE_R 2

// hook press key
# define RED_CROSS 17
# define ESC 53

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

typedef struct	s_sprite
{
	void	*wall;
	void	*exit;
	void	*coin;
	void	*player;
	void	*ground;
	int		width;
	int		height;
}				t_sprite;

typedef struct	s_map
{
	char		**map;
	int			width;
	int			height;
	t_sprite	v;
	t_tools		tools;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
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

// Initialize game with MinilibX
void	initialize_game(t_map *map, t_mlx *mlx);

// Tools for closing window
int		close_win(t_mlx *mlx);
int		key_exit(int keycode, t_mlx *mlx);

// Other tools
t_start find_start(char player, char **map);

/** Print & error functions **/
int		ft_error(int error);
int		check_extension(char *str);

/* remove this function before push */
void	print_map(t_map *map);

#endif

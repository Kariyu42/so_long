/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:17:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/31 11:24:04 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/**** libraries ****/
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/inc/libft.h"

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

// starting point for flood_fill function : check_paths();
typedef struct s_start
{
	int	x;
	int	y;
}				t_start;

typedef struct s_tools
{
	int	door;
	int	player;
	int	collects;
	int	moves;
}				t_tools;

typedef struct s_sprite
{
	void	*wall;
	void	*exit;
	void	*coin;
	void	*player;
	void	*ground;
	int		width;
	int		height;
}				t_sprite;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	t_sprite	v;
	t_tools		tools;
}				t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct s_game
{
	int		flood_c;
	int		flood_e;
	int		moves;
	int		valid_path;
	t_mlx	mlx;
	t_start	player;
	t_map	map;
}				t_game;

/** Initialize parameters **/
void	init_params(t_game *game);

// Map Parsing
char	*trim_newline(char *line);
int		get_map_height(char *filename);
char	**map_dup(char **plan, t_game *game);
int		search_char(char *line, t_game *game);
void	collect_map(char *filename, t_game *game);
int		check_walls(char *line, int index, t_game *game, int width);

// Free map function
void	free_map(char **plan);

// Initialize game with MinilibX
void	initialize_game(t_game *game);

// Tools for closing window
int		close_win(void);

// Other tools
t_start	find_start(char player, char **map);
void	move_player(t_game *game, int dir);
void	w_img(t_game *g, void *img, int x, int y);
void	quit_game(t_game *game);
void	put_images(t_game *g);

/** Print & error functions **/
int		ft_error(int error);
int		check_extension(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:40:56 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/15 11:40:57 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include"get_next_line.h"
# include<fcntl.h>
# include<stdlib.h>
# include"mlx/mlx.h"
# include<X11/X.h>
# include<X11/keysym.h>
# include<stdio.h>
# include<unistd.h>

# define WIN_WIDTH  600
# define WIN_HEIGHT 400
# define TILE_SIZE 50
# define NUM_IMAGES 9
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define TANK_UP    4
# define TANK_LEFT  7
# define TANK_DOWN  5
# define TANK_RIGHT 6

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*images[NUM_IMAGES];
	char	**map;
	int		collectables;
	int		moves;
	t_point	point;
	int		player_direction;
}t_game;

char	*ft_strdup(const char *s);
size_t	gft_strlen(const char *str);
int		check_single_e_p(char **map, int rows, char c);
int		check_one_collectible(char **map, int rows);
int		check_borders(char **map, int rows);
int		check_no_invalid_chars(char **map, int rows);
int		check_rec(char **map);
void	count_collectibles(t_game *game);
int		reachable_collectibles(char **tab, t_point size, t_point cur);
int		reachable_exit(char **tab, t_point size, t_point cur);
int		key_hook(int keycode, t_game *game);
int		close_window(void *param);
int		render_map(t_game *game);
int		move_player(int keycode, t_game *game);
int		load_images(t_game *game);
t_point	find_player_position(char **map);
char	**read_map_from_file(char *file);
t_point	count_lines(char *file);
int		count_all_collectibles(char **map);
void	free_2d_array(char **array);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
void	exit_program(t_game *game, int i);
char	**copy_map(char **map, t_point size);
int		reachable_collectibles(char **tab, t_point size, t_point cur);
int		reachable_exit(char **tab, t_point size, t_point cur);
void	valid_map(char **map, t_point point);
void	setup_hooks(t_game *game);
int		ft_putnbr(int nb);
void	render_wall(t_game *game, int x, int y);
void	render_floor(t_game *game, int x, int y);
void	render_exit(t_game *game, int x, int y);
void	render_collectable(t_game *game, int x, int y);
void	render_player(t_game *game, int x, int y);
int		ft_printf(const char *format, ...);

#endif

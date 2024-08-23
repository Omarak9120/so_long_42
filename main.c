/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:40:29 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/15 13:36:05 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

static char	*get_file_name(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("maps/mapi.ber");
		exit(1);
	}
	else if (argc == 2)
		return (argv[1]);
	else
	{
		ft_printf("Usage: %s [map_file.ber]\n", argv[0]);
		exit(1);
	}
}

static void	initialize_map(t_game *game, char *file_name)
{
	char	**map;
	t_point	point;

	map = read_map_from_file(file_name);
	if (!map || !map[0])
	{
		ft_printf("Error: Failed to load the map from file.\n");
		free_2d_array(map);
		exit(1);
	}
	point = count_lines(file_name);
	if (point.y == 0 || point.x == 0 || !check_rec(map))
	{
		ft_printf("Error: Map is empty or invalid.\n");
		free_2d_array(map);
		exit(1);
	}
	valid_map(map, point);
	game->point = point;
	game->map = map;
}

void	initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_program(game, 1);
	game->window = mlx_new_window(game->mlx, game->point.x * TILE_SIZE,
			game->point.y * TILE_SIZE, "So Long");
	if (game->window == NULL)
		exit_program(game, 2);
	if (load_images(game) != 0)
		exit_program(game, 3);
	count_collectibles(game);
	game->player_direction = 4;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	initialize_map(&game, get_file_name(argc, argv));
	initialize_game(&game);
	render_map(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	exit_program(&game, 3);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:56:25 by skreik            #+#    #+#             */
/*   Updated: 2024/08/14 22:35:56 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"  // Ensure libft functions are available

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
	game->player_direction = 4; // Assuming 4 is the initial direction
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*file_name;
	char	**map;
	t_point	point;

	// Initialize the game struct to avoid garbage values
	ft_bzero(&game, sizeof(t_game));

	// Handle command-line arguments
	if (argc == 1)
		file_name = "Maps/map.ber";
	else if (argc == 2)
		file_name = argv[1];
	else
	{
		ft_printf("Usage: %s [map_file.ber]\n", argv[0]);
		return (1);  // Exit with an error code if too many arguments
	}

	// Read and validate the map
	map = read_map_from_file(file_name);
	if (!map || !map[0])
	{
		ft_printf("Error: Failed to load the map from file.\n");
		free_2d_array(map); // Ensure memory is freed
		return (1);  // Return error code without using exit_program
	}

	point = count_lines(file_name);
	if (point.y == 0 || point.x == 0)  // Check if the map is empty or invalid
	{
		ft_printf("Error: Map is empty or invalid.\n");
		free_2d_array(map);
		return (1);  // Return error code without using exit_program
	}

	// Validate the map and set up the game
	if (!check_rec(map)) // If the map is not rectangular
	{
		ft_printf("Error: Map is not rectangular.\n");
		free_2d_array(map); // Ensure memory is freed
		return (1);
	}

	valid_map(map, point);
	game.point = point;
	game.map = map;
	initialize_game(&game);
	render_map(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	exit_program(&game, 3);
	return (0);
}


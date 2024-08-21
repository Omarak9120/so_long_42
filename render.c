/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:40:41 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/15 11:40:42 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->images[0], x * TILE_SIZE, y * TILE_SIZE);
}

void	render_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->images[1], x * TILE_SIZE, y * TILE_SIZE);
}

void	render_exit(t_game *game, int x, int y)
{
	if (game->collectables == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->images[8], x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->images[2], x * TILE_SIZE, y * TILE_SIZE);
}

void	render_collectable(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->images[3], x * TILE_SIZE, y * TILE_SIZE);
}

void	render_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->images[game->player_direction], x * TILE_SIZE, y * TILE_SIZE);
}

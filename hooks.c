/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:40:17 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/15 13:13:10 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_program(game, 4);
	else if (keycode == 'a' || keycode == 's'
		|| keycode == 'd' || keycode == 'w')
		move_player(keycode, game);
	return (0);
}

int	key_release(void)
{
	return (0);
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit_program(game, 4);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
}

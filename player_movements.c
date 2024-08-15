/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:40:36 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/15 18:31:18 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_new_position(int keycode, t_point *new,
		t_point player, t_game *game)
{
	new->x = player.x;
	new->y = player.y;
	if (keycode == 119)
	{
		new->y--;
		game->player_direction = TANK_UP;
	}
	else if (keycode == 115)
	{
		new->y++;
		game->player_direction = TANK_DOWN;
	}
	else if (keycode == 97)
	{
		new->x--;
		game->player_direction = TANK_LEFT;
	}
	else if (keycode == 100)
	{
		new->x++;
		game->player_direction = TANK_RIGHT;
	}
	ft_printf("New Position: x = %d, y = %d\n", new->x, new->y);
}

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	int	valid;

	valid = (new_y >= 0 && new_y < game->point.y
			&& new_x >= 0 && new_x < game->point.x);
	if (valid)
		ft_printf("Move to (x = %d, y = %d) is valid\n", new_x, new_y);
	else
		ft_printf("Move to (x = %d, y = %d) is invalid\n", new_x, new_y);
	return (valid);
}

void	handle_new_position(t_game *game, t_point player,
							t_point new, char new_pos)
{
	if (new_pos == 'E' && game->collectables != 0)
	{
		write(1, "YOU HAVE TO COLLECT ALL COLLECTIBLES FIRST!\n", 43);
		return ;
	}
	if (new_pos == 'C')
		game->collectables--;
	game->map[player.y][player.x] = '0';
	game->map[new.y][new.x] = 'P';
	game->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	if (new_pos == 'E' && game->collectables == 0)
	{
		write(1, "YOU WON!\n", 9);
		exit_program(game, 5);
	}
}

int	move_player(int keycode, t_game *game)
{
	t_point	player;
	t_point	new;
	char	new_pos;

	player = find_player_position(game->map);
	calculate_new_position(keycode, &new, player, game);
	if (is_valid_move(game, new.x, new.y) && game->map[new.y][new.x] != '1')
	{
		new_pos = game->map[new.y][new.x];
		handle_new_position(game, player, new, new_pos);
	}
	render_map(game);
	return (0);
}

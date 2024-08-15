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
    printf("New Position: x = %d, y = %d\n", new->x, new->y);
}

int	is_valid_move(t_game *game, int new_x, int new_y)
{
    int valid = (new_y >= 0 && new_y < game->point.y && new_x >= 0 && new_x < game->point.x);
    printf("Move to (x = %d, y = %d) is %s\n", new_x, new_y, valid ? "valid" : "invalid");
	return valid;
}

void	handle_move(t_game *game, t_point player, t_point new)
{
	char	new_pos;

	new_pos = game->map[new.y][new.x];
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
	render_map(game);
}

int	move_player(int keycode, t_game *game)
{
	t_point	player;
	t_point	new;
	char	new_pos;

	// Find the current position of the player
	player = find_player_position(game->map);

	// Calculate the new position based on the key pressed
	calculate_new_position(keycode, &new, player, game);

	// Check if the move is within bounds and not into a wall
	if (is_valid_move(game, new.x, new.y) && game->map[new.y][new.x] != '1')
	{
		new_pos = game->map[new.y][new.x];

		// Handle collectibles
		if (new_pos == 'C') 
			game->collectables--;

		// Update the player's position
		game->map[player.y][player.x] = '0';
		game->map[new.y][new.x] = 'P';
		game->moves++;  // Increment the move counter

		// Print the move count
		write(1, "Moves: ", 7);
		ft_putnbr(game->moves);
		write(1, "\n", 1);

		// Check if the player reached the exit and has collected all items
		if (new_pos == 'E' && game->collectables == 0)
		{
			write(1, "YOU WON!\n", 9);
			exit_program(game, 5);
		}
	}
	else
	{
		// If the move is into a wall or out of bounds, do nothing
		new_pos = '1';  // Re-assign to prevent any accidental step count
	}
	
	// Render the map again after the move attempt
	render_map(game);
	return (0);
}


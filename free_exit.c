/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:40:07 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/15 12:42:23 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	free_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_IMAGES)
	{
		if (game->images[i])
			mlx_destroy_image(game->mlx, game->images[i]);
		i++;
	}
}

void	free_2d_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exit_program(t_game *game, int status)
{
	if (game)
	{
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
		{
			free_images(game);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free_2d_array(game->map);
	}
	exit(status);
}

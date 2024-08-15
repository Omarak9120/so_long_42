/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:37:35 by skreik            #+#    #+#             */
/*   Updated: 2024/08/14 21:05:10 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_single_e_p(char **map, int rows, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count == 1);
}

int	check_one_collectible(char **map, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_borders(char **map, int rows)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < rows)
	{
		len = gft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_no_invalid_chars(char **map, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0'
					&& map[i][j] != 'P' && map[i][j] != 'E'
					&& map[i][j] != 'C')
			{
				// Debugging output for invalid characters
				printf("Invalid character '%c' (ASCII: %d) found at row %d, col %d\n",
					map[i][j], map[i][j], i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_rec(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (map[i] && map[i][k])
		k++;
	i++;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		if (k != j)
			return (0);
		i++;
	}
	return (1);
}

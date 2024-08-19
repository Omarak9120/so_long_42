/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:36:38 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/19 12:48:09 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

char	**read_map_from_file(char *file)
{
	int		fd;
	t_point	point;
	char	**store;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Failed to open map file.\n", 2);
		return (NULL);
	}
	point = count_lines(file);
	store = allocate_map_memory(point);
	if (!store)
	{
		close(fd);
		return (NULL);
	}
	store = fill_map_storage(fd, store);
	close(fd);
	return (store);
}

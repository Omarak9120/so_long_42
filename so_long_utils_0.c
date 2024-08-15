/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:40:45 by oabdelka          #+#    #+#             */
/*   Updated: 2024/08/15 18:10:48 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

t_point	count_lines(char *file)
{
	int		count;
	int		fd;
	char	*line;
	t_point	point;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ((t_point){-1, -1});
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		point.x = ft_strlen(line);
		free(line);
	}
	close(fd);
	point.y = count;
	return (point);
}

char	**copy_map(char **map, t_point size)
{
	char	**map_copy;
	int		i;
	int		j;

	i = 0;
	map_copy = malloc((size.y + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	map_copy[size.y] = NULL;
	while (i < size.y)
	{
		map_copy[i] = malloc((size.x + 1) * sizeof(char));
		if (!map_copy[i])
		{
			j = -1;
			while (++j < i)
				free(map_copy[j]);
			free(map_copy);
			return (NULL);
		}
		ft_strcpy(map_copy[i], map[i]);
		i++;
	}
	return (map_copy);
}

char	*trim_newline(char *str)
{
	char	*end;

	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == '\n' || *end == '\r' || *end == ' '))
		end--;
	*(end + 1) = '\0';
	return (str);
}

char	**read_map_from_file(char *file)
{
	int		fd;
	char	*line;
	t_point	point;
	char	**store;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Failed to open map file.\n", 2);
		return (NULL);
	}
	point = count_lines(file);
	store = (char **)malloc(sizeof(char *) * (point.y + 1));
	if (!store)
	{
		ft_putstr_fd("Error: Memory allocation failed for map storage.\n", 2);
		close(fd);
		return (NULL);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		store[i++] = ft_strdup(trim_newline(line));
		free(line);
	}
	store[point.y] = NULL;
	close(fd);
	if (i == 0)
	{
		free_2d_array(store);
		return (NULL);
	}
	return (store);
}

char	*ft_strcpy(char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

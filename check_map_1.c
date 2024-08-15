#include "so_long.h"

int	reachable_collectibles_recursive(char **tab, t_point size, t_point cur)
{
	int	count;

	count = 0;
	if (cur.y < 0 || cur.y >= size.y
		|| cur.x < 0
		|| cur.x >= size.x
		|| (tab[cur.y][cur.x] != 'P'
		&& tab[cur.y][cur.x] != '0'
		&& tab[cur.y][cur.x] != 'C'))
		return (count);
	if (tab[cur.y][cur.x] == 'C')
		count++;
	tab[cur.y][cur.x] = '1';
	count += reachable_collectibles_recursive(tab, size,
			(t_point){cur.x - 1, cur.y});
	count += reachable_collectibles_recursive(tab, size,
			(t_point){cur.x + 1, cur.y});
	count += reachable_collectibles_recursive(tab, size,
			(t_point){cur.x, cur.y - 1});
	count += reachable_collectibles_recursive(tab, size,
			(t_point){cur.x, cur.y + 1});
	return (count);
}

int	reachable_collectibles(char **tab, t_point size, t_point cur)
{
	char	**map_copy;
	int		count;

	count = 0;
	map_copy = copy_map(tab, size);
	if (!map_copy)
		return (0);
	count += reachable_collectibles_recursive(map_copy, size, cur);
	free_2d_array(map_copy);
	return (count);
}

int	reachable_exit_recursive(char **tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != 'P' && tab[cur.y][cur.x] != '0'
		&& tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'E'))
		return (0);
	if (tab[cur.y][cur.x] == 'E')
		return (1);
	tab[cur.y][cur.x] = '1';
	if (reachable_exit_recursive(tab, size, (t_point){cur.x - 1, cur.y}) ||
			reachable_exit_recursive(tab, size, (t_point){cur.x + 1, cur.y}) ||
			reachable_exit_recursive(tab, size, (t_point){cur.x, cur.y - 1}) ||
			reachable_exit_recursive(tab, size, (t_point){cur.x, cur.y + 1}))
		return (1);
	return (0);
}

int	reachable_exit(char **tab, t_point size, t_point cur)
{
	char	**map_copy;
	int		result;

	map_copy = copy_map(tab, size);
	if (!map_copy)
		return (0);
	result = reachable_exit_recursive(map_copy, size, cur);
	free_2d_array(map_copy);
	return (result);
}

void	valid_map(char **map, t_point point)
{
    printf("Validating map...\n");

    if (!check_rec(map))
    {
        printf("Error: Map is not rectangular.\n");
        exit(1);
    }
    if (!check_no_invalid_chars(map, point.y))
    {
        printf("Error: Invalid characters found.\n");
        exit(1);
    }
    if (!check_one_collectible(map, point.y))
    {
        printf("Error: No collectibles found.\n");
        exit(1);
    }
    if (!check_single_e_p(map, point.y, 'E'))
    {
        printf("Error: Invalid number of exits.\n");
        exit(1);
    }
    if (!check_single_e_p(map, point.y, 'P'))
    {
        printf("Error: Invalid number of player positions.\n");
        exit(1);
    }
    if (!check_borders(map, point.y))
    {
        printf("Error: Map borders are not enclosed.\n");
        exit(1);
    }
    if (!reachable_exit(map, point, find_player_position(map)))
    {
        printf("Error: Exit not reachable.\n");
        exit(1);
    }
    if (count_all_collectibles(map) != reachable_collectibles(map, point, find_player_position(map)))
    {
        printf("Error: Not all collectibles are reachable.\n");
        exit(1);
    }
    printf("Map validation passed.\n");
}

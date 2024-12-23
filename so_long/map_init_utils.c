/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:56:31 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/23 13:28:23 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_accessibility(t_data *data, t_map *map)
{
	find_player_position(data, map);
	flood_fill(map, data->p_y, data->p_x);
	if (map->reachable_collectibles < map->collectibles)
		map_error("Not all collectibles are accessible.", map);
	if (!map->exit_reachable)
		map_error("The exit is not accessible.", map);
}

void	flood_fill(t_map *map, size_t x, size_t y)
{
	if (x >= map->grid_rows || y >= map->grid_columns
		|| map->grid[x][y] == '1' || map->grid[x][y] == 'V'
		|| map->grid[x][y] == 'X')
		return ;
	if (map->grid[x][y] == 'C')
	{
		map->reachable_collectibles++;
		map->grid[x][y] = 'X';
	}
	if (map->grid[x][y] == 'E')
	{
		map->exit_reachable = 1;
		return ;
	}
	if (map->grid[x][y] != 'P' && map->grid[x][y] != 'X')
		map->grid[x][y] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	reset_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->grid_rows)
	{
		j = 0;
		while (j < map->grid_columns)
		{
			if (map->grid[i][j] == 'V')
				map->grid[i][j] = '0';
			if (map->grid[i][j] == 'X')
				map->grid[i][j] = 'C';
			j++;
		}
		i++;
	}
}

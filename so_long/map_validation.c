/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:56:59 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/18 12:35:59 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(t_map *map)
{
	size_t	i;
	size_t	line_len;

	i = 0;
	line_len = line_length(map->grid[0]);
	while (i < map->grid_rows)
	{
		if (line_length(map->grid[i]) != line_len)
			map_error("Map is not rectangular.", map);
		i++;
	}
}

void	check_boundaries(t_map *map)
{
	size_t	i;

	if (map->grid_columns == 0 || map->grid_rows == 0)
		map_error("Map is not properly formatted.", map);
	i = 0;
	while (i < map->grid_columns)
	{
		if (map->grid[0][i] != '1' || map->grid[map->grid_rows - 1][i] != '1')
			map_error("No walls at top/bottom of the map.", map);
		i++;
	}
	i = 0;
	while (i < map->grid_rows)
	{
		if (map->grid[i][0] != '1'
				|| map->grid[i][map->grid_columns - 1] != '1')
			map_error("No walls at the sides of the map.", map);
		i++;
	}
}

void	count_entities(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->grid_rows)
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'E')
				map->exit_count++;
			else if (map->grid[i][j] == 'P')
				map->start_count++;
			else if (map->grid[i][j] == 'C')
				map->collectibles++;
			else if (map->grid[i][j] != '0' && map->grid[i][j] != '1' &&
					map->grid[i][j] != 'P' && map->grid[i][j] != 'E'
					&& map->grid[i][j] != 'C')
				map_error("Invalid entity in map.", map);
			j++;
		}
		i++;
	}
}

void	check_entity_count(t_map *map)
{
	if (map->exit_count != 1)
		map_error("Map must have exactly one exit.", map);
	if (map->start_count != 1)
		map_error("Map must have exactly one entrance.", map);
	if (map->collectibles < 1)
		map_error("Map must have at least one collectible.", map);
}

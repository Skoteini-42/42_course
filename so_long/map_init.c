/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:56:45 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/18 12:33:49 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->filepath, O_RDONLY);
	if (fd < 0)
		map_error("Error opening map file.", map);
	line = get_next_line(fd);
	while (line)
	{
		if (map->grid_rows == 0)
			map->grid_columns = line_length(line);
		add_line(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map->grid_rows == 0)
		map_error("Empty map.", map);
	validate_map(map);
	return (1);
}

void	add_line(t_map *map, char *line)
{
	char	**temp;
	size_t	i;

	temp = malloc(sizeof(char *) * (map->grid_rows + 2));
	if (!temp)
		map_error("Memory allocation failed.", map);
	i = 0;
	if (map->grid)
	{
		while (i < map->grid_rows)
		{
			temp[i] = map->grid[i];
			i++;
		}
		free(map->grid);
	}
	temp[map->grid_rows] = clean_line(line);
	if (!temp[map->grid_rows])
		map_error("Memory allocation failed for line.", map);
	temp[map->grid_rows + 1] = NULL;
	map->grid = temp;
	map->grid_rows++;
}

char	*clean_line(const char *line)
{
	char	*cleaned;
	size_t	len;

	len = ft_strlen(line);
	cleaned = ft_strdup(line);
	if (!cleaned)
		return (NULL);
	if (len > 0 && cleaned[len - 1] == '\n')
		cleaned[len - 1] = '\0';
	return (cleaned);
}

void	validate_map(t_map *map)
{
	check_rectangular(map);
	check_boundaries(map);
	count_entities(map);
	check_entity_count(map);
}

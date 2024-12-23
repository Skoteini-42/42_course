/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:57:49 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/23 15:16:52 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (argc == 1)
		arg_error("No map input.");
	else if (argc > 2)
		arg_error("Too many arguments.");
	else if (argc == 2 && !check_file_type(argv[1]))
		arg_error("Invalid map file.");
	init_data(&data);
	init_map(&map);
	data.map = &map;
	map.filepath = argv[1];
	read_map(&map);
	check_accessibility(&data, &map);
	reset_map(&map);
	init_game(&data, &map);
	return (0);
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->player_img = NULL;
	data->player2_img = NULL;
	data->exit1_img = NULL;
	data->exit2_img = NULL;
	data->collectible_img = NULL;
	data->wall_img = NULL;
	data->background_img = NULL;
	data->p_x = 0;
	data->p_y = 0;
	data->direction = 0;
	data->win_width = 0;
	data->win_height = 0;
	data->img_width = 0;
	data->img_height = 0;
	data->move_count = 0;
	data->tile_size = 0;
	data->map = NULL;
	data->bpp = 0;
	data->endian = 0;
	data->size_line = 0;
}

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->grid_rows = 0;
	map->grid_columns = 0;
	map->filepath = NULL;
	map->start_count = 0;
	map->collectibles = 0;
	map->exit_reachable = 0;
	map->exit_count = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->reachable_collectibles = 0;
}

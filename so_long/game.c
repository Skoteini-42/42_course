/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:55:58 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/18 16:43:48 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_window_size(t_data *data, t_map *map)
{
	data->tile_size = 32;
	data->win_width = map->grid_columns * data->tile_size;
	data->win_height = map->grid_rows * data->tile_size;
}

void	init_game(t_data *data, t_map *map)
{
	calculate_window_size(data, map);
	find_player_position(data, map);
	data->mlx = mlx_init();
	data->win = mlx_new_window
		(data->mlx, data->win_width, data->win_height, "So long!");
	data->background_img = mlx_xpm_file_to_image
		(data->mlx, "textures/bg3.xpm", &data->tile_size, &data->tile_size);
	data->wall_img = mlx_xpm_file_to_image
		(data->mlx, "textures/wall1.xpm", &data->tile_size, &data->tile_size);
	data->collectible_img = mlx_xpm_file_to_image
		(data->mlx, "textures/coll1.xpm", &data->tile_size, &data->tile_size);
	data->exit1_img = mlx_xpm_file_to_image
		(data->mlx, "textures/exit1.xpm", &data->tile_size, &data->tile_size);
	data->exit2_img = mlx_xpm_file_to_image
		(data->mlx, "textures/exit2.xpm", &data->tile_size, &data->tile_size);
	data->player_img = mlx_xpm_file_to_image
		(data->mlx, "textures/player.xpm", &data->tile_size, &data->tile_size);
	data->player2_img = mlx_xpm_file_to_image
		(data->mlx, "textures/player2.xpm", &data->tile_size, &data->tile_size);
	render_game(data);
	mlx_key_hook(data->win, key_handler, data);
	mlx_hook(data->win, 17, 0, close_handler, data);
	mlx_loop(data->mlx);
}

void	find_player_position(t_data *data, t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->grid_columns)
	{
		x = 0;
		while (x < map->grid_rows)
		{
			if (map->grid[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	collect_item(t_data *data)
{
	data->map->grid[data->p_y][data->p_x] = '0';
	data->map->collectibles--;
	render_game(data);
}

int	attempt_exit(t_data *data)
{
	if (data->map->collectibles == 0)
		close_handler(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:57:32 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/18 11:45:18 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_data *data)
{
	size_t	x;
	size_t	y;

	data->img_width = 32;
	data->img_height = 32;
	x = 0;
	while (x < data->win_width)
	{
		y = 0;
		while (y < data->win_height)
		{
			mlx_put_image_to_window
				(data->mlx, data->win, data->background_img, x, y);
			y = y + data->img_height;
		}
		x = x + data->img_width;
	}
}

void	render_map(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->map->grid_rows)
	{
		x = 0;
		while (x < data->map->grid_columns)
		{
			if (data->map->grid[y][x] == '1')
				mlx_put_image_to_window
					(data->mlx, data->win, data->wall_img, x * 32, y * 32);
			else if (data->map->grid[y][x] == 'C')
				fix_background(data, x * 32, y * 32, data->collectible_img);
			else if (data->map->grid[y][x] == 'E')
			{
				if (data->map->collectibles == 0)
					fix_background(data, x * 32, y * 32, data->exit2_img);
				else
					fix_background(data, x * 32, y * 32, data->exit1_img);
			}
			x++;
		}
		y++;
	}
}

void	render_player(t_data *data)
{
	fix_background(data, data->p_x * 32, data->p_y * 32, data->player_img);
	if (data->direction == 'd'
		&& data->map->grid[data->p_y][data->p_x + 1] != '1')
		fix_background(data, data->p_x * 32, data->p_y * 32, data->player_img);
	else if (data->direction == 'a'
		&& data->map->grid[data->p_y][data->p_x - 1] != '1')
		fix_background(data, data->p_x * 32, data->p_y * 32, data->player2_img);
}

void	render_game(t_data *data)
{
	render_background(data);
	render_map(data);
	render_player(data);
}

void	fix_background(t_data *data, int x, int y, void *img)
{
	int		pixel_x;
	int		pixel_y;
	int		sprite_color;
	char	*img_data;

	data->img_width = 32;
	data->img_height = 32;
	img_data = mlx_get_data_addr
		(img, &data->bpp, &data->size_line, &data->endian);
	pixel_y = 0;
	while (pixel_y < data->img_height)
	{
		pixel_x = 0;
		while (pixel_x < data->img_width)
		{
			sprite_color = ((int *)img_data)
			[pixel_y * data->img_width + pixel_x];
			if (sprite_color != 0xFF0000)
				mlx_pixel_put(data->mlx,
					data->win, x + pixel_x, y + pixel_y, sprite_color);
			pixel_x++;
		}
		pixel_y++;
	}
}

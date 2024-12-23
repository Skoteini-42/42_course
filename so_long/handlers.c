/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:57:19 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/18 16:45:50 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_handler(data);
	else if (keycode == 'w'
		&& data->map->grid[data->p_y - 1][data->p_x] != '1')
		data->p_y--;
	else if (keycode == 's'
		&& data->map->grid[data->p_y + 1][data->p_x] != '1')
		data->p_y++;
	else if (keycode == 'a'
		&& data->map->grid[data->p_y][data->p_x - 1] != '1')
		data->p_x--;
	else if (keycode == 'd'
		&& data->map->grid[data->p_y][data->p_x + 1] != '1')
		data->p_x++;
	move_hook(keycode, data);
	key_hook(keycode, data);
	if (data->map->grid[data->p_y][data->p_x] == 'C')
		collect_item(data);
	else if (data->map->grid[data->p_y][data->p_x] == 'E')
		attempt_exit(data);
	render_game(data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 'd')
		data->direction = 'd';
	else if (keycode == 'a')
		data->direction = 'a';
	return (0);
}

void	move_hook(int keycode, t_data *data)
{
	if (keycode == 'w'
		&& data->map->grid[data->p_y - 1][data->p_x] != '1')
	{
		data->move_count++;
		ft_printf("Move count: %d\n", data->move_count);
	}
	else if (keycode == 's'
		&& data->map->grid[data->p_y + 1][data->p_x] != '1')
	{
		data->move_count++;
		ft_printf("Move count: %d\n", data->move_count);
	}
	else if (keycode == 'a'
		&& data->map->grid[data->p_y][data->p_x - 1] != '1')
	{
		data->move_count++;
		ft_printf("Move count: %d\n", data->move_count);
	}
	else if (keycode == 'd'
		&& data->map->grid[data->p_y][data->p_x + 1] != '1')
	{
		data->move_count++;
		ft_printf("Move count: %d\n", data->move_count);
	}
}

int	close_handler(t_data *data)
{
	size_t	i;

	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	mlx_destroy_image(data->mlx, data->background_img);
	mlx_destroy_image(data->mlx, data->wall_img);
	mlx_destroy_image(data->mlx, data->collectible_img);
	mlx_destroy_image(data->mlx, data->exit1_img);
	mlx_destroy_image(data->mlx, data->exit2_img);
	mlx_destroy_image(data->mlx, data->player_img);
	mlx_destroy_image(data->mlx, data->player2_img);
	i = 0;
	while (i < data->map->grid_rows)
	{
		free(data->map->grid[i]);
		i++;
	}
	free(data->map->grid);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}

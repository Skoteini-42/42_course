/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:58:00 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/23 13:27:02 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_map	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*player2_img;
	void	*exit1_img;
	void	*exit2_img;
	void	*collectible_img;
	void	*wall_img;
	void	*background_img;
	int		p_x;
	int		p_y;
	size_t	win_width;
	size_t	win_height;
	int		img_width;
	int		img_height;
	int		move_count;
	int		tile_size;
	int		bpp;
	int		size_line;
	int		endian;
	char	direction;
	t_map	*map;
}		t_data;

typedef struct s_map
{
	char	**grid;
	size_t	grid_rows;
	size_t	grid_columns;
	char	*filepath;
	int		start_count;
	size_t	collectibles;
	int		exit_count;
	size_t	start_x;
	size_t	start_y;
	size_t	reachable_collectibles;
	int		exit_reachable;
}		t_map;

int		main(int argc, char **argv);
int		check_file_type(char *str);
void	init_data(t_data *data);
void	init_map(t_map *map);
int		read_map(t_map *map);
void	add_line(t_map *map, char *line);
char	*clean_line(const char *line);
size_t	line_length(char *str);
void	arg_error(char *str);
void	map_error(char *str, t_map *map);
void	free_map(t_map *map);
void	validate_map(t_map *map);
void	check_rectangular(t_map *map);
void	check_boundaries(t_map *map);
void	count_entities(t_map *map);
void	check_entity_count(t_map *map);
void	check_accessibility(t_data *data, t_map *map);
void	flood_fill(t_map *map, size_t x, size_t y);
void	reset_map(t_map *map);
int		key_handler(int keycode, t_data *data);
void	move_hook(int keycode, t_data *data);
int		close_handler(t_data *data);
void	init_game(t_data *data, t_map *map);
void	find_player_position(t_data *data, t_map *map);
void	calculate_window_size(t_data *data, t_map *map);
void	render_background(t_data *data);
void	render_map(t_data *data);
void	render_player(t_data *data);
void	render_game(t_data *data);
void	collect_item(t_data *data);
int		attempt_exit(t_data *data);
void	fix_background(t_data *data, int x, int y, void *img);
int		key_hook(int keycode, t_data *data);

#endif

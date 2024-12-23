/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:59:02 by fpapadak          #+#    #+#             */
/*   Updated: 2024/12/23 12:20:31 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	line_length(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

void	arg_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit (1);
}

void	map_error(char *str, t_map *map)
{
	if (map && map->grid)
		free_map(map);
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit (1);
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->grid_rows)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

int	check_file_type(char *str)
{
	size_t	len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'r' && str[len - 1] == 'e'
		&& str[len - 2] == 'b' && str[len - 3] == '.')
		return (1);
	return (0);
}

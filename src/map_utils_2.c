/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:20:20 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 22:29:12 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_cell(t_map *map, int x, int y)
{
	if (map->array[y][x] == 'C')
		map->c += 1;
	else if (map->array[y][x] == 'E')
	{
		map->e += 1;
		map->exit_x = x;
		map->exit_y = y;
	}
	else if (map->array[y][x] == 'P')
		map->p += 1;
	else if (map->array[y][x] != '0' && map->array[y][x] != '1')
		error_map_elements(map);
}

void	check_param(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			check_cell(map, x, y);
			x++;
		}
		y++;
	}
	if (map->c < 1 || map->e < 1 || map->p != 1)
		error_map_elements(map);
}

void	check_route(t_map *map)
{
	map->c_check = map->c;
	map->e_check = map->e;
	check_player(map);
	change_route(map->player.x, map->player.y, map);
	if (map->c_check != 0 || map->e_check >= map->e)
	{
		ft_printf(2, "Error\n");
		ft_printf(2, "No valid path");
		free_array(map->array, map->y);
		free_array(map->copy, map->y);
		exit(EXIT_FAILURE);
	}
}

void	create_map_array(t_map *map)
{
	int	fd;

	map->y = 0;
	map->line = "";
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		open_error();
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		map->file = ft_strjoin_freed(map->file, map->line);
		free(map->line);
		if (!map->file)
			free_exit_map(map);
		map->y++;
	}
	close(fd);
	map->array = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if (!map->array || !map->copy)
		free_exit_map(map);
	free(map->file);
}

void	exit_map(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	map->moves++;
	mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
	map->array[y][x] = '0';
	y--;
	map->player.y = y;
	mlx_image_to_window(map->mlx, map->img.exit_open, x * PXL_IMG, y * PXL_IMG);
	mlx_image_to_window(map->mlx, map->img.player_up1, x * PXL_IMG, y
		* PXL_IMG);
	map->array[y][x] = 'P';
	print_moves(map);
	ft_printf(1, "Has ganado\n");
	close_game(map);
}

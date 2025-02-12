/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:09:57 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 17:55:08 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_initializer(t_map *map, char **av)
{
	map->filename = av[1];
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
}
void	check_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->x)
	{
		if (map->array[0][x] != '1')
			wall_error(map);
		x++;
	}
	x = 0;
	while (x < map->x)
	{
		if (map->array[map->y - 1][x] != '1')
			wall_error(map);
		x++;
	}
	y = 0;
	while (y < map->y)
	{
		if (map->array[y][0] != '1' || map->array[y][map->x - 1] != '1')
			wall_error(map);
		y++;
	}
}

void	check_file(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->filename);
	if (map->filename[len - 1] != 'r')
		file_error();
	if (map->filename[len - 2] != 'e')
		file_error();
	if (map->filename[len - 3] != 'b')
		file_error();
	if (map->filename[len - 4] != '.')
		file_error();
	if (!ft_strnstr(map->filename, ".ber", ft_strlen(map->filename)))
		file_error();
}

void	validate_map(t_map *map)
{
	check_file(map);
	create_map_array(map);
	check_size(map);
	check_wall(map);
	check_param(map);
	check_route(map);
	free_array(map->copy, map->y);
}

void	check_size(t_map *map)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	x = 0;
	max = ft_strlen(map->array[y]);
	while (y < map->y)
	{
		x = ft_strlen(map->array[y]);
		if (max != x)
			size_error(map);
		y++;
	}
	map->x = max;
}

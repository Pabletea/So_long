/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:41:12 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 22:49:42 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_exit_tile(t_map *map, int x, int y)
{
	mlx_image_to_window(map->mlx, map->img.exit, x * PXL_IMG, y * PXL_IMG);
	map->array[y][x] = 'E';
}

void	clear_previous_tile(t_map *map, int x, int y)
{
	if (map->array[y][x] != 'E')
		map->array[y][x] = '0';
	mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
}

void	update_player_position(t_map *map, int nx, int ny,
		mlx_image_t *player_img)
{
	map->moves++;
	print_moves(map);
	mlx_image_to_window(map->mlx, player_img, nx * PXL_IMG, ny * PXL_IMG);
	map->array[ny][nx] = 'P';
	map->player.x = nx;
	map->player.y = ny;
}

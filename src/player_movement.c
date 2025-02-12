/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:18:47 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 22:54:12 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_map *map, int dx, int dy, mlx_image_t *player_img)
{
	int	x;
	int	y;
	int	nx;
	int	ny;

	x = map->player.x;
	y = map->player.y;
	nx = x + dx;
	ny = y + dy;
	if (map->array[ny][nx] == '1')
		return ;
	if (map->array[ny][nx] == 'C' && --map->c == 0)
		map->exit = 1;
	if (x == map->exit_x && y == map->exit_y)
		update_exit_tile(map, x, y);
	else if (map->array[ny][nx] == 'E' && map->exit == 1)
		exit_map(map);
	else
		clear_previous_tile(map, x, y);
	update_player_position(map, nx, ny, player_img);
}

void	move_up(t_map *map)
{
	move_player(map, 0, -1, map->img.player_up1);
}

void	move_down(t_map *map)
{
	move_player(map, 0, 1, map->img.player_down_basic1);
}

void	move_left(t_map *map)
{
	move_player(map, -1, 0, map->img.player_left1);
}

void	move_right(t_map *map)
{
	move_player(map, 1, 0, map->img.player_right1);
}

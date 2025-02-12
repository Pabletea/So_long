/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:18:47 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 20:01:08 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->array[y - 1][x] != '1')
	{
		if (map->array[y - 1][x] == 'C')
		{
			map->c--;
			if (map->c == 0)
				map->exit = 1;
		}
		if (x == map->exit_x && y == map->exit_y)
		{
			mlx_image_to_window(map->mlx, map->img.exit, x * PXL_IMG, y
				* PXL_IMG);
			map->array[y][x] = 'E';
		}
		else
		{
			if (map->array[y - 1][x] == 'E' && map->exit == 1)
				exit_map(map);
			else
			{
				if (map->array[y][x] != 'E')
					map->array[y][x] = '0';
				mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
			}
		}
		y--;
		map->moves++;
		print_moves(map);
		mlx_image_to_window(map->mlx, map->img.player_up1, x * PXL_IMG, y * PXL_IMG);
		map->array[y][x] = 'P';
		map->player.y = y;
	}
}

void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y - 1 && map->array[y + 1][x] != '1')
	{
		if (map->array[y + 1][x] == 'C')
		{
			map->c--;
			if (map->c == 0)
				map->exit = 1;
		}
		if (x == map->exit_x && y == map->exit_y)
		{
			mlx_image_to_window(map->mlx, map->img.exit, x * PXL_IMG, y
				* PXL_IMG);
			map->array[y][x] = 'E';
		}
		else
		{
			if (map->array[y + 1][x] == 'E' && map->exit == 1)
				exit_map(map);
			else
			{
				if (map->array[y][x] != 'E')
					map->array[y][x] = '0';
				mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y* PXL_IMG);
			}
		}
		y++;
		map->moves++;
		print_moves(map);
		mlx_image_to_window(map->mlx, map->img.player_down_basic1, x * PXL_IMG,
			y * PXL_IMG);
		map->array[y][x] = 'P';
		map->player.y = y;
	}
}

void	move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->array[y][x - 1] != '1')
	{
		if (map->array[y][x - 1] == 'C')
		{
			map->c--;
			if (map->c == 0)
				map->exit = 1;
		}
		if (x == map->exit_x && y == map->exit_y)
		{
			mlx_image_to_window(map->mlx, map->img.exit, x * PXL_IMG, y
				* PXL_IMG);
			map->array[y][x] = 'E';
		}
		else
		{
			if (map->array[y][x - 1] == 'E' && map->exit == 1)
				exit_map(map);
			else
			{
				if (map->array[y][x] != 'E')
					map->array[y][x] = '0';
				mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
			}
		}
		x--;
		map->moves++;
		print_moves(map);
		mlx_image_to_window(map->mlx, map->img.player_left1, x * PXL_IMG, y * PXL_IMG);
		map->array[y][x] = 'P';
		map->player.x = x;
	}
}

void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x - 1 && map->array[y][x + 1] != '1')
	{
		if (map->array[y][x + 1] == 'C')
		{
			map->c--;
			if (map->c == 0)
				map->exit = 1;
		}
		if (x == map->exit_x && y == map->exit_y)
		{
			mlx_image_to_window(map->mlx, map->img.exit, x * PXL_IMG, y
				* PXL_IMG);
			map->array[y][x] = 'E';
		}
		else
		{
			if (map->array[y][x + 1] == 'E' && map->exit == 1)
				exit_map(map);
			else
			{
				if (map->array[y][x] != 'E')
					map->array[y][x] = '0';
				mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
			}
		}
		x++;
		map->moves++;
		print_moves(map);
		mlx_image_to_window(map->mlx, map->img.player_right1, x * PXL_IMG, y * PXL_IMG);
		map->array[y][x] = 'P';
		map->player.x = x;
	}
}

void	exit_map(t_map *map)
{
	int x;
	int y;
	
	x = map->player.x;
	y = map->player.y;
	map->moves++;
	mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
	map->array[y][x] = '0';
	y--;
	map->player.y = y;
	mlx_image_to_window(map->mlx, map->img.exit_open, x * PXL_IMG, y * PXL_IMG);
	mlx_image_to_window(map->mlx, map->img.player_up1, x * PXL_IMG, y * PXL_IMG);
	map->array[y][x] = 'P';
	print_moves(map);
	ft_printf(1, "Has ganado\n");
	close_game(map);
}

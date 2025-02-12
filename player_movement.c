/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:18:47 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 14:30:01 by pabalons         ###   ########.fr       */
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
			{
				map->exit = 1; // Se desbloquea la salida
				ft_printf(1, "¡La salida está desbloqueada!\n");
			}
		}
		move_resume(map, x, y, UP);
		if (map->array[y - 1][x] == 'E' && map->exit == 1)
			exit_map(map);
		map->moves++;
        mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
		map->array[y][x] = '0';
		y--;
		print_moves(map);
        mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
        mlx_image_to_window(map->mlx, map->img.player_up1, x * PXL_IMG + 8, y * PXL_IMG);
		map->array[y][x] = 'P';
		map->player.x = x;
	}
}

void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y && map->array[y + 1][x] != '1')
	{
		if (map->array[y + 1][x] == 'C')
		{
			map->c--;
			if (map->c == 0)
				map->exit = 1; // Se desbloquea la salida
		}
		move_resume(map, x, y, DOWN);
		if (map->array[y + 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			exit_map(map);
		map->moves++;
        mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
		map->array[y][x] = '0';
		y++;
        mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
        mlx_image_to_window(map->mlx, map->img.player_down1, x * PXL_IMG + 8, y * PXL_IMG);
		map->array[y][x] = 'P';
		print_moves(map);
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
				map->exit = 1; // Se desbloquea la salida
		}
		move_resume(map, x, y, LEFT);
		if (map->array[y][x - 1] == 'E' && (map->c != 0 || map->exit == 1))
			exit_map(map);
		map->moves++;
        mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
		map->array[y][x] = '0';
		x--;
		print_moves(map);
        mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
        mlx_image_to_window(map->mlx, map->img.player_left1, x * PXL_IMG, y * PXL_IMG);
		map->array[y][x] = 'P';
		map->player.y = y;
	}
}

void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x && map->array[y][x + 1] != '1')
	{
		if (map->array[y][x + 1] == 'C')
		{
			map->c--;
			if (map->c == 0)
				map->exit = 1; // Se desbloquea la salida
		}
		move_resume(map, x, y, RIGHT);
		if (map->array[y][x + 1] == 'E' && (map->c != 0 || map->exit == 1))
			exit_map(map);
		map->moves++;
        mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
		map->array[y][x] = '0';
		x++;
        mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
        mlx_image_to_window(map->mlx, map->img.player_right1, x * PXL_IMG, y * PXL_IMG);
		map->array[y][x] = 'P';
		print_moves(map);
	}
	map->player.x = x;
}

void exit_map(t_map *map)
{
	int x;
	int y;
	x = map->player.x;
	y = map->player.y;
    // Player steps on the unlocked exit
    map->moves++; // Increment move count

    // Clear the player's old position
    mlx_image_to_window(map->mlx, map->img.empty, x * PXL_IMG, y * PXL_IMG);
    map->array[y][x] = '0'; // Mark the old position as empty

    // Move player to the exit's position
    y--; // Update player's Y coordinate
    map->player.y = y;

    // Redraw the exit (it stays 'E' in the array)
    mlx_image_to_window(map->mlx, map->img.exit_open, x * PXL_IMG, y * PXL_IMG);

    // Draw the player sprite over the exit
    mlx_image_to_window(map->mlx, map->img.player_up1, x * PXL_IMG + 8, y * PXL_IMG);

    // Mark the player's position in the array
    map->array[y][x] = 'P'; // Player is now on the exit

    // Print the number of moves
    print_moves(map);

    // End the game (e.g., display a win message and close the game)
    ft_printf(1, "Has ganado\n"); // Print win message
    close_game(map); // Call function to exit the game
}
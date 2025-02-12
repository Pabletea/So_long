/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:14:30 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 21:58:50 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_map(t_map *map, int x, int y)
{
	mlx_image_t	*img;

	img = NULL;
	if (map->array[y][x] == '0')
		img = map->img.empty;
	else if (map->array[y][x] == '1')
		img = map->img.wall;
	else if (map->array[y][x] == 'E')
		img = map->img.exit;
	else if (map->array[y][x] == 'C')
		img = map->img.collectible;
	else if (map->array[y][x] == 'P')
		img = map->img.player_down1;
	if (img)
		mlx_image_to_window(map->mlx, img, x * PXL_IMG, y * PXL_IMG);
}

void	map_printer(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			put_image_to_map(map, x, y);
			x++;
		}
		y++;
	}
}

void	load_player_textures_part1(t_map *map)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resources/textures/player/player_left1.png");
	map->img.player_left1 = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/player/player_right1.png");
	map->img.player_right1 = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/player/player_up1.png");
	map->img.player_up1 = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/player/player_down1.png");
	map->img.player_down1 = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
}

void	load_player_textures_part2(t_map *map)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resources/textures/player/player_left1.png");
	map->img.player_left2 = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/player/player_right1.png");
	map->img.player_right2 = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/player/player_up1.png");
	map->img.player_up2 = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/player/player_down1.png");
	map->img.player_down2 = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/player/player_down2.png");
	map->img.player_down_basic1 = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
}

void	file_to_image_player(t_map *map)
{
	load_player_textures_part1(map);
	load_player_textures_part2(map);
}

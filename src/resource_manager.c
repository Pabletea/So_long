/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:14:30 by pabalons          #+#    #+#             */
/*   Updated: 2025/02/12 17:55:24 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_printer(t_map *map)
{
	int			y;
	int			x;
	mlx_image_t	*img;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
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
			x++;
		}
		y++;
	}
}

void	file_to_image_player(t_map *map)
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
	texture = mlx_load_png("./resources/textures/player/player_down_basic1.png");
	map->img.player_down_basic1 = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
}

void	file_to_image(t_map *map)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resources/textures/map/empty.png");
	map->img.empty = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/map/wall.png");
	map->img.wall = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/map/exit_closed.png");
	map->img.exit = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/map/exit_open.png");
	map->img.exit_open = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./resources/textures/map/collectible.png");
	map->img.collectible = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	file_to_image_player(map);
}

void	free_images(t_map *map)
{
	if (!map || !map->mlx)
		return ;
	if (map->img.player_left1)
	{
		mlx_delete_image(map->mlx, map->img.player_left1);
		map->img.player_left1 = NULL;
	}
	if (map->img.player_right1)
	{
		mlx_delete_image(map->mlx, map->img.player_right1);
		map->img.player_right1 = NULL;
	}
	if (map->img.player_up1)
	{
		mlx_delete_image(map->mlx, map->img.player_up1);
		map->img.player_up1 = NULL;
	}
	if (map->img.player_down1)
	{
		mlx_delete_image(map->mlx, map->img.player_down1);
		map->img.player_down1 = NULL;
	}
	if (map->img.player_left2)
	{
		mlx_delete_image(map->mlx, map->img.player_left2);
		map->img.player_left2 = NULL;
	}
	if (map->img.player_right2)
	{
		mlx_delete_image(map->mlx, map->img.player_right2);
		map->img.player_right2 = NULL;
	}
	if (map->img.player_up2)
	{
		mlx_delete_image(map->mlx, map->img.player_up2);
		map->img.player_up2 = NULL;
	}
	if (map->img.player_down2)
	{
		mlx_delete_image(map->mlx, map->img.player_down2);
		map->img.player_down2 = NULL;
	}
	if (map->img.player_down_basic1)
	{
		mlx_delete_image(map->mlx, map->img.player_down_basic1);
		map->img.player_down_basic1 = NULL;
	}
	if (map->img.empty)
	{
		mlx_delete_image(map->mlx, map->img.empty);
		map->img.empty = NULL;
	}
	if (map->img.wall)
	{
		mlx_delete_image(map->mlx, map->img.wall);
		map->img.wall = NULL;
	}
	if (map->img.exit)
	{
		mlx_delete_image(map->mlx, map->img.exit);
		map->img.exit = NULL;
	}
	if (map->img.exit_open)
	{
		mlx_delete_image(map->mlx, map->img.exit_open);
		map->img.exit_open = NULL;
	}
	if (map->img.collectible)
	{
		mlx_delete_image(map->mlx, map->img.collectible);
		map->img.collectible = NULL;
	}
}
